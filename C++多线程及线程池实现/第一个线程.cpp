#include <iostream>
#include <thread>
using namespace std;

bool is_exit = false;

// 线程入口函数
void ThreadMain()
{
    cout << "子线程开始: " << this_thread::get_id() << endl;
    for (int i = 0; i < 10; i++)
    {
        if (!is_exit)
            break; // 用标识通知线程退出
        cout << "线程运行中 " << i << endl;
        this_thread::sleep_for(chrono::seconds(1)); // 1000ms
    }
    cout << "子线程结束: " << this_thread::get_id() << endl;
}

int main()
{
    cout << "main thread ID" << this_thread::get_id() << endl;
    // 线程创建启动
    thread th(ThreadMain);
    th.detach(); // 线程分离，守护线程
    // 注：主线程退出后，子线程还可能会访问进程资源

    this_thread::sleep_for(chrono::seconds(1)); // 1000ms
    is_exit = true;                             // 通知子线程退出
    cout << "主线程退出，等待子线程退出！" << endl;
    // 阻塞等待子线程退出
    // th.join()
    cout << "子线程已经退出！" << endl;

    return 0;
}