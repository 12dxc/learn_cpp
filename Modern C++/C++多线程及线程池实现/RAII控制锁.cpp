#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <shared_mutex>
using namespace std;

// RAII实现互斥锁，自动释放
class XMutex
{
public:
    XMutex(mutex &mux) : mux_(mux)
    {
        cout << "Lock" << endl;
        mux_.lock();
    }
    ~XMutex()
    {
        cout << "Unlock" << endl;
        mux_.unlock();
    }

private:
    mutex &mux_;
};
static mutex mux;
void TestMutex(int status)
{
    XMutex lock(mux);
    if (status == 1)
    {
        cout << "== 1" << endl;
        return;
    }
    else
    {
        cout << "!= 1" << endl;
        return;
    }
}

static mutex gmutex;
void TestLockGuard(int i)
{
    gmutex.lock();
    {
        // 已经拥有锁，不上锁
        lock_guard<mutex> lock(gmutex, adopt_lock);
        // 结束释放锁
    }
    {
        cout << "begin thread " << i << endl;
    }
    while (1)
    {
        {
            lock_guard<mutex> lock(gmutex);
            cout << "In " << i << endl;
        }
        this_thread::sleep_for(500ms);
    }
}

static mutex mux1;
static mutex mux2;
void TestScop1()
{
    this_thread::sleep_for(100ms); // 模拟死锁 停100ms等另一个线程锁mux2
    cout << "begin mux1 lock" << endl;
    // mux1.lock();
    cout << "begin mux2 lock" << endl;
    // mux2.lock(); // 死锁
    // lock(mux1, mux2);//C++11
    scoped_lock lock(mux1, mux2); // 统一管理多个互斥锁
    cout << "TestScop1" << endl;
    this_thread::sleep_for(1000ms);
    // mux1.unlock();
    // mux2.unlock();
}
void TestScop2()
{
    mux2.lock();
    cout << "begin mux2 lock" << endl;
    this_thread::sleep_for(100ms);
    mux1.lock(); // 死锁
    cout << "begin mux1 lock" << endl;
    cout << "TestScop2" << endl;
    this_thread::sleep_for(1500ms);
    mux1.unlock();
    mux2.unlock();
}

int main()
{
    // scoped_lock C++17 用于多个互斥体的免死锁 RAII 封装
    {
        // 演示死锁  多锁次序有问题
        {
            thread th(TestScop1);
            th.detach();
        }
        {
            thread th(TestScop2);
            th.detach();
        }
    }
    getchar();

    // shared_lock C++14 实现可移动的共享互斥体所有权封装器
    {
        // 共享锁
        static shared_timed_mutex tmux;
        // 读取锁  共享锁
        {
            // 调用共享锁
            shared_lock<shared_timed_mutex> lock(tmux);
            cout << "read data" << endl;
            // 退出栈区
        }
        // 写入锁  互斥锁
        {
            unique_lock<shared_timed_mutex> lock(tmux);
            cout << "write data" << endl;
        }
    }
    // unique_lock C++11 实现可移动的互斥体所有权包装器
    {
        static mutex mux;
        {
            unique_lock<mutex> lock(mux);
            lock.unlock();
            // 临时释放锁
            lock.lock();
        }
        {
            // 已经拥有锁，不锁定，退出栈区解锁
            mux.lock();
            unique_lock<mutex> lock(mux, adopt_lock);
        }
        {
            // 延时加锁 不拥有 退出栈区不解锁
            unique_lock<mutex> lock(mux, defer_lock);
            // 加锁 退出栈区解锁
            lock.lock();
        }
        {
            // 尝试加锁 不阻塞 失败不再拥有锁
            unique_lock<mutex> lock(mux, try_to_lock);
            {
                if (lock.owns_lock())
                {
                    cout << "owns_lock" << endl;
                }
                else
                {
                    cout << "not owns_lock" << endl;
                }
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        thread th(TestLockGuard, i + 1);
        th.detach();
    }

    getchar();
    TestMutex(1);
    TestMutex(2);

    return 0;
}