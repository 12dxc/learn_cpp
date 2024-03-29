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
#include "Any.h"
#include "semaphore.h"

class Task; // Task类型的前置声明

// 实现接收提交到线程池的task任务执行完后的返回值Result
class Result
{
public:
    Result(std::shared_ptr<Task> task, bool isValid = true);
    ~Result() = default;

    // 问题一：setVal方法，获取任务执行完的返回值的
    void setVal(Any any);

    // 问题二：get方法，用户调用这个方法获取task的返回值
    Any get();

private:
    Any any_;                    // 存储任务的返回值
    semaphore sem_;              // 线程通信信号量
    std::shared_ptr<Task> task_; // 指向对应获取返回值的对象
    std::atomic_bool isValid_;   // 返回值是否有效
};

// 任务抽象基类
class Task
{
public:
    Task();
    ~Task() = default;

    void exec();
    void setResult(Result *res);

    // 用户可自定义任意任务类型，从Task继承，重写run方法，实现自定义任务处理
    virtual Any run() = 0;

private:
    Result *result_; // Result对象生命周期长于Task
};
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
    Thread(ThreadFunc func);
    // 线程析构
    ~Thread();

    // 启动线程
    void start();

    // 获取线程id
    int getId() const;

private:
    ThreadFunc func_;
    static int generateId_;
    int threadId_; // 保存线程id
};

// 线程池类型
class ThreadPool
{
public: // 初始化和个性化设置
    // 线程池构造
    ThreadPool();
    // 线程池构析构
    ~ThreadPool();

    // 设置task任务队列上限阈值
    void setTaskQueMaxSize(int threshhold);

    // 设置线程池cached模式下线程阈值
    void setThreadMaxSize(int threshhold);

    // 禁止对线程池进行拷贝或赋值
    ThreadPool(const ThreadPool &) = delete;
    ThreadPool &operator=(const ThreadPool &) = delete;

public: // 逻辑处理
    // 给线程池提交任务
    Result submitTask(std::shared_ptr<Task> sp);

    // 开启线程池
    void start(int initThreadSize = std::thread::hardware_concurrency(), PoolMode mode = PoolMode::MODE_FIXED);

private:
    // 定义线程函数  任务创建在线程池类中，但线程还需访问池类变量，故将线程执行函数定义在池类中
    void threadFunc(int threadId);

    // 检查pool的运行状态
    bool checkRunningState() const;

private:
    // std::vector<std::unique_ptr<Thread>> threads_; // 线程列表
    std::unordered_map<int, std::unique_ptr<Thread>> threads_;
    int initThreadSize_;             // 初始线程数量
    std::atomic_int threadSize_;     // 记录当前线程池数量
    int threadMaxSize_;              // 线程数量上限阈值
    std::atomic_int idleThreadSize_; // 空闲线程数量

    std::queue<std::shared_ptr<Task>> taskQue_; // 任务队列
    std::atomic_int taskSize_;                  // 任务数量
    int taskQueMaxSize_;                        // 任务队列数量上限阈值

    std::mutex taskQueMtx_;            // 保证任务队列的线程安全
    std::condition_variable notFull_;  // 表示任务队列不满
    std::condition_variable notEmpty_; // 表示任务队列不空
    std::condition_variable exitCond_; // 等待线程资源全部回收

    PoolMode poolMode_;          // 当前线程池工作模式
    std::atomic_bool isPoolRun_; // 表示线程池是否运行
};

#endif
