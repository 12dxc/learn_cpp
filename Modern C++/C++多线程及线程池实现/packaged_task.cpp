#include <iostream>
#include <thread>
#include <future>
#include <string>
using namespace std;

string TestPack(int index)
{
    cout << "begin Test Pack " << index << endl;
    this_thread::sleep_for(2s);
    return "Test Pack return";
}
int main()
{
    // 函数指针类型
    packaged_task<string(int)> task(TestPack);
    auto res = task.get_future();
    // task(100);

    thread th(move(task), 101);

    cout << "begin res get" << endl;
    cout << "res get " << res.get() << endl;

    th.join();
    getchar();
    return 0;
}