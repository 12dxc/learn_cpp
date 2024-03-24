#include "threadpool.h"

using namespace std;

const int THREAD_MAX_SIZE = 1024;    // 最大任务数
const int TASK_MAX_SIZE = 100;       // 最大线程数
const int THREAD_MAX_IDLE_TIME = 60; // 单位：秒  最大空闲时间

// 线程池构造
ThreadPool::ThreadPool()
    : initThreadSize_(0), taskSize_(0), idleThreadSize_(0), threadSize_(0),
      threadMaxSize_(THREAD_MAX_SIZE), taskQueMaxSize_(TASK_MAX_SIZE),
      poolMode_(PoolMode::MODE_FIXED), isPoolRun_(false) {}
// 线程池构析构
ThreadPool::~ThreadPool()
{
    this->isPoolRun_ = false;
    notEmpty_.notify_all();

    // 等待线程池里面所有的线程返回，有两种状态：阻塞 & 正在执行任务中
    unique_lock<mutex> lock;
    exitCond_.wait(lock, [&]() -> bool
                   { return threads_.size() == 0; });
}
// 设置task任务队列上限阈值
void ThreadPool::setTaskQueMaxSize(int threshhold)
{
    if (checkRunningState())
        return;
    this->taskQueMaxSize_ = threshhold;
}
// 设置线程池cached模式下线程阈值
void ThreadPool::setThreadMaxSize(int threshhold)
{
    if (checkRunningState())
        return;
    if (poolMode_ == PoolMode::MODE_CACHED)
        this->threadMaxSize_ = threshhold;
}
// 给线程池提交任务  用户调用该接口，传入任务对象，生产任务
Result ThreadPool::submitTask(shared_ptr<Task> sp)
{
    // 1、获取锁  队列并非线程安全，插入和删除不能同时进行
    unique_lock<mutex> lock(taskQueMtx_);

    // 2、线程的通信  等待任务队列有空余
    // 用户提交任务，最长不能阻塞超过1s，否则判断提交任务失败，返回
    if (!notFull_.wait_for(lock, chrono::seconds(1),
                           [&]() -> bool
                           { return taskQue_.size() < (size_t)taskQueMaxSize_; }))
    {
        // 表示notFull_等待1s，条件依然没有满足
        cerr << "task queue is full,submit task fail." << endl;
        // return task->getResult();  // Task  Result   线程执行完task，task对象就被析构掉了
        return Result(sp, false);
    }

    // 3、如果有空余，把任务放入任务队列中
    taskQue_.emplace(sp);
    ++taskSize_;

    // 4、因为新放了任务，任务队列肯定不空了，在notEmpty_上进行通知
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
    return Result(sp);
    // return task->getResult();
}
// 开启线程池
void ThreadPool::start(int initThreadSize, PoolMode mode)
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
        auto ptr = make_unique<Thread>(bind(&ThreadPool::threadFunc, this, placeholders::_1));
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
// 定义线程函数  线程池的所有线程从任务队列里面消费
void ThreadPool::threadFunc(int threadId)
{
    auto lastTime = chrono::high_resolution_clock().now();
    // 所有任务执行完成，才能回收线程资源
    for (;;)
    {
        shared_ptr<Task> task;
        {
            // 1、先获取锁
            unique_lock<mutex> lock(taskQueMtx_);

            cout << "tid:" << this_thread::get_id()
                 << " 尝试获取任务..." << endl;

            // cached模式下，有可能已经创建了很多的线程，但是空闲时间超过60，应把多余线程结束回收掉
            while (taskQue_.size() == 0)
            {
                if (!isPoolRun_)
                {
                    threads_.erase(threadId);
                    cout << "threadid:" << this_thread::get_id() << " exit!" << endl;
                    exitCond_.notify_all();
                    return; // 结束线程函数，就是结束当前线程
                }
                if (poolMode_ == PoolMode::MODE_CACHED)
                {
                    // 条件变量，超时返回了
                    if (cv_status::timeout == notEmpty_.wait_for(lock, chrono::seconds(1)))
                    {
                        auto now = chrono::high_resolution_clock().now();
                        auto dur = chrono::duration_cast<chrono::seconds>(now - lastTime);
                        if (dur.count() >= THREAD_MAX_IDLE_TIME && threadSize_ > initThreadSize_)
                        {
                            // 开始回收当前线程
                            // 记录线程数量的相关变量的值修改
                            // 把线程对象从线程列表容器中删除   没有办法 threadFunc <=> thread对象
                            // threadid => thread对象 => 删除
                            threads_.erase(threadId);
                            --threadSize_;
                            --idleThreadSize_;

                            cout << "threadid:" << this_thread::get_id() << " exit!" << endl;
                            return;
                        }
                    }
                }
                else
                {
                    // 2、等待notEmpty_条件
                    notEmpty_.wait(lock);
                }
                // 线程池要结束，回收线程资源
                // if (!isPoolRun_)
                // {
                //     threads_.erase(threadId);
                //     cout << "threadid:" << this_thread::get_id() << " exit!" << endl;
                //     exitCond_.notify_all();
                //     return; // 结束线程函数，就是结束当前线程
                // }
            }

            --idleThreadSize_;

            cout << "tid:" << this_thread::get_id()
                 << " 获取任务成功..." << endl;

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

        // 4、当前线程负责执行这个任务
        if (task != nullptr) // 保守处理，可不加
        {
            // task->run(); //执行任务；把任务返回值setVal方法给到Result
            task->exec();
        }
        ++idleThreadSize_;
        lastTime = chrono::high_resolution_clock().now(); // 更新线程执行完任务的时间
    }
}
bool ThreadPool::checkRunningState() const
{
    return isPoolRun_;
}

// -----------------------> 线程方法实现 <-----------------------
int Thread::generateId_ = 0;
// 线程构造
Thread::Thread(ThreadFunc func)
    : func_(func), threadId_(generateId_++) {}
// 线程析构
Thread::~Thread() {}
// 启动线程
void Thread::start()
{
    // 创建一个线程来执行一个线程函数
    thread t(func_, threadId_); // C++11来说  线程对象t，和线程函数func_
    t.detach();
}
// 获取线程id
int Thread::getId() const
{
    return this->threadId_;
}
// ------------------------> Task方法实现 <------------------------
Task::Task() : result_(nullptr) {}

void Task::exec()
{
    if (result_ != nullptr)
        result_->setVal(run()); // 这里发生多态调用
}

void Task::setResult(Result *res)
{
    result_ = res;
}

// -----------------------> Result方法实现 <-----------------------
Result::Result(shared_ptr<Task> task, bool isValid)
    : task_(task), isValid_(isValid)
{
    task_->setResult(this);
}

Any Result::get() // 用户调用的
{
    if (!isValid_)
        return "";
    sem_.wait(); // 任务如果没有执行完，这里会阻塞用户的线程
    return move(any_);
}

void Result::setVal(Any any) // Task调用
{
    // 存储task的返回值
    this->any_ = move(any);
    sem_.post(); // 已经获取了任务的返回值，增加信号量资源
}
