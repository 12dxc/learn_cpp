#include <iostream>
#include <vector>
#include <functional>
#include <thread>
using namespace std;

// 用function和bind实现简易线程池
class Thread
{
public:
    Thread(function<void()> func) : func_(func) {}
    // 线程启动
    thread start()
    {
        thread t(func_);
        return t;
    }

private:
    function<void()> func_;
};
class ThreadPool
{
public:
    ThreadPool() {}
    ~ThreadPool()
    {
        // 释放Thread对象占用的堆资源
        for (auto i : pool_)
            delete i;
    }
    void startPool(int size)
    {
        // 创建线程
        for (int i = 0; i < size; ++i)
            // 要将成员方法作为线程入口函数，只能借助于bind 将其绑定至线程对象
            pool_.push_back(new Thread(bind(&ThreadPool::run, this, i)));
        // 保持线程句柄并启动每个线程
        for (auto i : pool_)
            handler_.push_back(i->start());
        // 销毁池中线程
        for (thread &t : handler_)
            t.join();
    }

private:
    vector<Thread *> pool_;  // 线程池变量
    vector<thread> handler_; // 保持线程的句柄

    // 将成员方法充当线程函数
    void run(int id)
    {
        cout << "call run id: " << id << endl;
    }
};

int main()
{

    ThreadPool pool;
    pool.startPool(10);

    return 0;
}