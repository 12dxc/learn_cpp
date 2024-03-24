#include <thread>
#include <iostream>
#include <string>
#include <mutex>
using namespace std;

static mutex mux;
void TestThread()
{
    while (1)
    {
        // 获取锁资源，如果没有则阻塞等待
        // mux.lock();
        if (!mux.try_lock()) // 尝试获取锁，没有锁就继续向下执行
        {
            cout << "." << flush;
            this_thread::sleep_for(100ms);
            continue;
        }
        cout << "---------------------" << endl;
        cout << "test 001" << endl;
        cout << "test 002" << endl;
        cout << "test 003" << endl;
        cout << "---------------------" << endl;
        mux.unlock();
    }
}
void ThreadMainMux(int i)
{
    while (1)
    {
        mux.lock();
        cout << "[" << i << "] ing.." << endl;
        this_thread::sleep_for(1000ms);
        mux.unlock();
        // 解锁时，操作系统还没回收资源，就又马上加锁了；加一个延迟，来避免此情况
        this_thread::sleep_for(1ms);
    }
}
// 超时锁
timed_mutex tmux; // 在规定的时间获取锁
void ThreadMainTime(int i)
{
    while (1)
    {

        if (tmux.try_lock_for(chrono::milliseconds(500))) // 500ms
        {
            // 如果未在规定时间内拿到锁，那么这段代码可能会出现问题，这里可以进行日志的写入，便于调试
            cout << i << "[try_lock_for timeout]" << endl;
            continue;
        }
        cout << "[" << i << "] ing.." << endl;
        this_thread::sleep_for(2000ms);
        tmux.unlock();
        this_thread::sleep_for(1ms);
    }
}

recursive_mutex rmux; // 递归锁（可重用，锁几次就解几次）
void Task1()
{
    rmux.lock();
    cout << "task1 [in]" << endl;
    rmux.unlock();
}
void Task2()
{
    rmux.lock();
    cout << "task2 [in]" << endl;
    rmux.unlock();
}
void ThreadMainRec(int i)
{
    while (1)
    {
        rmux.lock();
        Task1();
        cout << "[" << i << "] ing.." << endl;
        this_thread::sleep_for(2000ms);
        Task2();
        rmux.unlock();
        this_thread::sleep_for(1ms);
    }
}
int main(int argc, char *argv[])
{
    for (int i = 0; i < 3; i++)
    {
        thread th(ThreadMainRec, i + 1);
        th.detach();
    }

    getchar();
    for (int i = 0; i < 3; i++)
    {
        thread th(ThreadMainTime, i + 1);
        th.detach();
    }

    getchar();
    for (int i = 0; i < 3; i++)
    {
        thread th(ThreadMainMux, i + 1);
        th.detach();
    }

    getchar();
    for (int i = 0; i < 10; i++)
    {
        thread th(TestThread);
        th.detach();
    }

    getchar();
    return 0;
}