#include <thread>
#include <iostream>
#include <string>
#include <mutex>
#include <shared_mutex>
using namespace std;

// C++ 17
shared_mutex smux;
// C++ 14
shared_timed_mutex stmux; // 底层为读写锁，有两种模式，共享和互斥，共享可多人使用，互斥则独占使用权

void ThreadRead(int i)
{
    while (1)
    {
        stmux.lock_shared();
        cout << i << " Read" << endl;
        this_thread::sleep_for(500ms);
        stmux.unlock_shared();
        this_thread::sleep_for(1ms);
    }
}
void ThreadWrite(int i)
{
    while (1)
    {
        stmux.lock();
        cout << i << " Write" << endl;
        this_thread::sleep_for(300ms);
        stmux.unlock();
        this_thread::sleep_for(1ms);
    }
}
int main(int argc, char *argv[])
{
    for (int i = 0; i < 3; i++)
    {
        thread th(ThreadWrite, i + 1);
        th.detach();
    }
    for (int i = 0; i < 3; i++)
    {
        thread th(ThreadRead, i + 1);
        th.detach();
    }

    getchar(); // 避免主线程结束，不能看到子线程运行结果

    return 0;
}