#pragma once
#include <thread>
#include <mutex>
#include <vector>
#include <list>
#include <functional>
#include <atomic>
#include <future>

//任务基类，用于自定义自己的线程任务
class XTask
{
public:
    virtual int Run() = 0;
    std::function<bool()> is_exit = nullptr;
    auto GetReturn()
    {
        // 阻塞等待 set_value
        return p_.get_future().get();
    }
    void SetValue(int v)
    {
        p_.set_value(v);
    }

private:
    // 接收返回值
    std::promise<int> p_;
};

class XThreadPoll
{
public:
    // 初始化线程
    //@para num 线程数量
    void Init(int num);

    // 启动所有线程，必须先调用Init
    void Start();

    // 线程池退出
    void Stop();

    // 追加任务
    // void AddTask(XTask *task);
    void AddTask(std::shared_ptr<XTask> task);

    // 获取任务
    // XTask *GetTask();
    std::shared_ptr<XTask> GetTask();

    bool is_exit() const { return is_exit_; }
    int task_run_count() { return task_run_count_; }

    ~XThreadPoll() { Stop(); }
private:
    // 线程池的入口函数
    void Run();
    int thread_num_ = 0; // 线程数量
    std::mutex mux_;
    // std::vector<std::thread *> threads_;
    std::vector<std::shared_ptr<std::thread>> threads_;

    // std::list<XTask*>tasks_;
    std::list<std::shared_ptr<XTask>> tasks_;
    std::condition_variable cv_;
    bool is_exit_ = false; // 线程池退出

    // 正在运行的任务数量
    std::atomic<int> task_run_count_ = { 0 }; // 线程安全
};