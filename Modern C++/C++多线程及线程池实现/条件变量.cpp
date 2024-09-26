#include <iostream>
#include <thread>
#include <string>
#include <list>
#include <mutex>
#include <sstream>
#include <condition_variable>
using namespace std;

list<string> msgs;
mutex mux;
condition_variable cv;
void ThreadWrite()
{
    for (int i = 0;; i++)
    {
        stringstream ss;
        ss << "Write msg " << i;
        unique_lock<mutex> lock(mux);
        msgs.push_back(ss.str());
        lock.unlock();
        cv.notify_one(); // 发送信号
        this_thread::sleep_for(3s);
    }
}
void ThreadRead(int i)
{
    while (1)
    {
        cout << "read msg" << endl;
        unique_lock<mutex> lock(mux);
        // cv.wait(lock); // 解锁、阻塞等待信号
        cv.wait(lock, [i]()
                { 
                    cout<<i<<"wait"<<endl;
                    return !msgs.empty(); });
        // 获取信号后锁定
        while (!msgs.empty())
        {
            cout << i << " read " << msgs.front() << endl;
            msgs.pop_front();
        }
    }
}
int main()
{
    thread th(ThreadWrite);
    th.detach();
    for (int i = 0; i < 3; i++)
    {
        thread th(ThreadRead, i + 1);
        th.detach();
    }
    getchar();

    return 0;
}