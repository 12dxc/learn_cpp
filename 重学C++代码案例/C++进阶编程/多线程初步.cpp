#include<thread>
#include<mutex>
#include<iostream>
using namespace std;

mutex g_mutex;  //实例锁
void T1()
{
    g_mutex.lock();  //加锁，使得程序执行完，才轮到其他线程
    cout << "T1 Hello" << endl;
    g_mutex.unlock();   //解锁
}

void T2(const char* str)
{
    g_mutex.lock();
    cout << "T2" << str << endl;
    g_mutex.unlock();
}

int main()
{
    thread t1(T1);
    thread t2(T2, "Hello World");
    t1.join();   //等待子线程执行完
    t2.join();

    cout << "Main Hi" << endl;

    system("pause");
    return 0;
}