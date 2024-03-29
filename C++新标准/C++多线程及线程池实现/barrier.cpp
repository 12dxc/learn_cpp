#include <iostream>
#include <vector>
#include <barrier>
#include <thread>
using namespace std;

// barrier C++20屏障，等待给定量的线程都到达后，再执行
void TestBar(int i, barrier<> *bar)
{
    this_thread::sleep_for(chrono::seconds(i));
    cout << i << " begin wait" << endl;
    bar->wait(bar->arrive()); // 期待数-1 阻塞等待，期待为0时返回
    cout << i << " end wait" << endl;
}
int main()
{
    int count = 3;
    barrier bar(3); // 初始数量
    for (int i = 0; i < count; i++)
    {
        thread th(TestBar, i + 1, &bar);
        th.detach();
    }
    getchar();
    return 0;
}