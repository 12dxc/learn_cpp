#include <iostream>
#include <thread>
#include <future>
#include <string>
using namespace std;

void TestFuture(promise<string> p)
{
    cout << "bengin TestFuture" << endl;
    this_thread::sleep_for(3s);
    cout << "begin set value" << endl;
    p.set_value("TestFuture value");
    this_thread::sleep_for(3s);
    cout << "end TestFuture" << endl;
}
int main()
{
    // 异步传输变量存储
    promise<string> p;
    // 用来获取线程异步值
    auto futrue = p.get_future();

    auto th = thread(TestFuture, move(p));

    cout << "begin futrue.get()" << endl;
    cout << "futrue get() = " << futrue.get() << endl;
    cout << "end futrue.get()" << endl;
    th.join();

    getchar();

    return 0;
}