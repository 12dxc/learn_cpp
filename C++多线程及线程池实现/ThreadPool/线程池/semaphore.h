#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <mutex>
#include <condition_variable>
#include <atomic>

// C++20才加入信号量，故这里用互斥锁+条件变量实现一个信号量类
class semaphore
{
public:
    semaphore(int limit = 0) : resLimit_(limit), isExit_(false) {}
    ~semaphore() { isExit_ = true; }

    // 获取一个信号量资源
    void wait()
    {
        if (isExit_)
            return;
        std::unique_lock<std::mutex> lock(mux_);
        // 等待信号量有资源，没有资源会阻塞当前线程
        cond_.wait(lock, [&]() -> bool
                   { return resLimit_ > 0; });
        --resLimit_;
    }

    // 增加一个信号量资源
    void post()
    {
        if (isExit_)
            return;
        std::unique_lock<std::mutex> lock(mux_);
        ++resLimit_;
        // linux下condition_variable的析构函数什么也没做
        // 导致这里状态已经失效，无故阻塞
        cond_.notify_all(); // 等待状态，释放mutex锁 通知条件变量wait的地方，可以起来干活了
    }

private:
    std::atomic_int isExit_;
    int resLimit_; // 信号计数
    std::mutex mux_;
    std::condition_variable cond_;
};

#endif