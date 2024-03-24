#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <iostream>
#include <vector>
#include <queue>
#include <memory>
#include <atomic>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <unordered_map>
#include <thread>
#include <future>

const int THREAD_MAX_SIZE = 1024;    // 最大任务数
const int TASK_MAX_SIZE = 100;       // 最大线程数
const int THREAD_MAX_IDLE_TIME = 60; // 单位：秒  最大空闲时间

// 线程池支持的模式
enum class PoolMode
{
    MODE_FIXED,  // 固定数量的线程
    MODE_CACHED, // 线程数量可动态增长
};

// 线程类型
class Thread
{
public:
    using ThreadFunc = std::function<void(int)>; // 线程函数对象类型

    // 线程构造
    Thread(ThreadFunc func) : func_(func), threadId_(generateId_++) {}
    // 线程析构
    ~Thread() = default;

    // 启动线程
    void start()
    {
        // 创建一个线程来执行一个线程函数
        std::thread t(func_, threadId_); // C++11来说  线程对象t，和线程函数func_
        t.detach();
    }

    // 获取线程id
    int getId() const { return this->threadId_; }

private:
    ThreadFunc func_;
    static int generateId_;
    int threadId_; // 保存线程id
};

int Thread::generateId_ = 0;

// 线程池类型
class ThreadPool
{
public: // 初始化和个性化设置
    // 线程池构造
    ThreadPool() : initThreadSize_(0), taskSize_(0), idleThreadSize_(0), threadSize_(0),
                   threadMaxSize_(THREAD_MAX_SIZE), taskQueMaxSize_(TASK_MAX_SIZE),
                   poolMode_(PoolMode::MODE_FIXED), isPoolRun_(false) {}
    // 线程池构析构
    ~ThreadPool()
    {
        this->isPoolRun_ = false;
        notEmpty_.notify_all();

        // 等待线程池里面所有的线程返回，有两种状态：阻塞 & 正在执行任务中
        std::unique_lock<std::mutex> lock;
        exitCond_.wait(lock, [&]() -> bool
                       { return threads_.size() == 0; });
    }

    // 设置task任务队列上限阈值
    void setTaskQueMaxSize(int threshhold)
    {
        if (checkRunningState())
            return;
        this->taskQueMaxSize_ = threshhold;
    }

    // 设置线程池cached模式下线程阈值
    void setThreadMaxSize(int threshhold)
    {
        if (checkRunningState())
            return;
        if (poolMode_ == PoolMode::MODE_CACHED)
            this->threadMaxSize_ = threshhold;
    }

    // 禁止对线程池进行拷贝或赋值
    ThreadPool(const ThreadPool &) = delete;
    ThreadPool &operator=(const ThreadPool &) = delete;

    // 给线程池提交任务  使用可变惨模板，使其可以接收任意任务函数和任意数量的参数，返回值需要是future
    template <typename Func, typename... Args>
    auto submitTask(Func &&func, Args &&...args) -> std::future<decltype(func(args...))>
    {
        // 打包任务，放入任务队列
        using RType = decltype(func(args...));
        auto task = std::make_shared<std::packaged_task<RType()>>(
            std::bind(std::forward<Func>(func), std::forward<Args>(args)...));
        std::future<RType> result = task->get_future();

        // 获取锁
        unique_lock<mutex> lock(taskQueMtx_);

        // 用户提交任务，最长不能阻塞超过1s，否则判断提交任务失败，返回
        if (!notFull_.wait_for(lock, chrono::seconds(1),
                               [&]() -> bool
                               { return taskQue_.size() < (size_t)taskQueMaxSize_; }))
        {
            // 表示notFull_等待1s，条件依然没有满足
            cerr << "task queue is full,submit task fail." << endl;
            auto task = std::make_shared<std::packaged_task<RType()>>(
                []() -> RType
                { return RType(); });
            return task->get_future();
        }

        // 如果有空余，把任务放入任务队列中
        taskQue_.emplace([task]()
                         { (*task)(); });
        ++taskSize_;

        // 因为新放了任务，任务队列肯定不空了，在notEmpty_上进行通知
        notEmpty_.notify_all();

        // 5、需要根据任务数量和空闲线程的数量，判断是否需要创建新的线程出来
        if (poolMode_ == PoolMode::MODE_CACHED && taskSize_ > idleThreadSize_ && threadSize_ < threadMaxSize_)
        {
            cout << ">>> create new thread..." << endl;
            // 创建新线程
            auto ptr = make_unique<Thread>(bind(&ThreadPool::threadFunc, this, placeholders::_1));
            int threadId = ptr->getId();
            threads_.emplace(threadId, move(ptr));
            // 启动线程
            threads_[threadId]->start();
            // 修改线程个数相关变量
            ++threadSize_;
            ++idleThreadSize_;
        }

        // 6、返回任务的Result对象
        return result;
    }

    // 开启线程池
    void start(int initThreadSize = std::thread::hardware_concurrency(), PoolMode mode = PoolMode::MODE_FIXED)
    {
        // 设置线程池的运行状态
        isPoolRun_ = true;
        // 记录初始线程个数
        this->initThreadSize_ = initThreadSize;
        this->threadSize_ = initThreadSize;
        // 更改线程池模式
        this->poolMode_ = mode;

        // 创建线程对象
        for (int i = 0; i != initThreadSize_; ++i)
        {
            // 创建thread线程对象的时候，把线程函数给到thread线程对象
            auto ptr = std::make_unique<Thread>(std::bind(&ThreadPool::threadFunc, this, std::placeholders::_1));
            int threadId = ptr->getId();
            threads_.emplace(threadId, move(ptr));
            // threads_.emplace_back(move(ptr));
        }

        // 启动所有线程
        for (auto &i : threads_)
        {
            i.second->start(); // 需要执行线程函数
            ++idleThreadSize_; // 记录初始空闲线程数量
        }
    }

private:
    // 定义线程函数  任务创建在线程池类中，但线程还需访问池类变量，故将线程执行函数定义在池类中
    void threadFunc(int threadId)
    {
        auto lastTime = std::chrono::high_resolution_clock().now();
        // 所有任务执行完成，才能回收线程资源
        for (;;)
        {
            Task task;
            {
                // 1、先获取锁
                std::unique_lock<std::mutex> lock(taskQueMtx_);

                std::cout << "tid:" << std::this_thread::get_id()
                          << " 尝试获取任务..." << std::endl;

                // cached模式下，有可能已经创建了很多的线程，但是空闲时间超过60，应把多余线程结束回收掉
                while (taskQue_.size() == 0)
                {
                    if (!isPoolRun_)
                    {
                        threads_.erase(threadId);
                        std::cout << "threadid:" << std::this_thread::get_id() << " exit!" << std::endl;
                        exitCond_.notify_all();
                        return; // 结束线程函数，就是结束当前线程
                    }
                    if (poolMode_ == PoolMode::MODE_CACHED)
                    {
                        // 条件变量，超时返回了
                        if (std::cv_status::timeout == notEmpty_.wait_for(lock, std::chrono::seconds(1)))
                        {
                            auto now = std::chrono::high_resolution_clock().now();
                            auto dur = std::chrono::duration_cast<std::chrono::seconds>(now - lastTime);
                            if (dur.count() >= THREAD_MAX_IDLE_TIME && threadSize_ > initThreadSize_)
                            {

                                threads_.erase(threadId);
                                --threadSize_;
                                --idleThreadSize_;

                                std::cout << "threadid:" << std::this_thread::get_id() << " exit!" << std::endl;
                                return;
                            }
                        }
                    }
                    else
                    {
                        // 2、等待notEmpty_条件
                        notEmpty_.wait(lock);
                    }
                }

                --idleThreadSize_;

                std::cout << "tid:" << std::this_thread::get_id()
                          << " 获取任务成功..." << std::endl;

                // 3、从任务队列中取一个任务出来
                task = taskQue_.front();
                taskQue_.pop();
                --taskSize_;

                // 如果依然有剩余任务，继续通知其他的线程执行任务
                if (taskQue_.size() > 0)
                    notEmpty_.notify_all();

                // 取出一个任务，进行通知可以继续提交生产任务
                notFull_.notify_all();
            } // 此处就该释放锁，因为处理任务是当前线程专属操作，无需加锁

            // 当前线程负责执行这个任务
            if (task != nullptr)
            {
                task(); // 执行function<void()>
            }
            ++idleThreadSize_;
            lastTime = std::chrono::high_resolution_clock().now(); // 更新线程执行完任务的时间
        }
    }

    // 检查pool的运行状态
    bool checkRunningState() const
    {
        return isPoolRun_;
    }

private:
    std::unordered_map<int, std::unique_ptr<Thread>> threads_; // 线程列表
    int initThreadSize_;                                       // 初始线程数量
    std::atomic_int threadSize_;                               // 记录当前线程池数量
    int threadMaxSize_;                                        // 线程数量上限阈值
    std::atomic_int idleThreadSize_;                           // 空闲线程数量

    // Task -> 任务对象
    using Task = std::function<void()>;
    std::queue<Task> taskQue_; // 任务队列
    std::atomic_int taskSize_; // 任务数量
    int taskQueMaxSize_;       // 任务队列数量上限阈值

    std::mutex taskQueMtx_;            // 保证任务队列的线程安全
    std::condition_variable notFull_;  // 表示任务队列不满
    std::condition_variable notEmpty_; // 表示任务队列不空
    std::condition_variable exitCond_; // 等待线程资源全部回收

    PoolMode poolMode_;          // 当前线程池工作模式
    std::atomic_bool isPoolRun_; // 表示线程池是否运行
};

#endif
