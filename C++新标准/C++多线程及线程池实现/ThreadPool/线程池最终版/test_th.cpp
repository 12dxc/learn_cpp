// 线程池项目-最终版.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <functional>
#include <thread>
#include <future>
#include <chrono>
using namespace std;
#include "threadpool.h"

/*
如何能让线程池提交任务更加方便
1. pool.submitTask(sum1, 10, 20);
   pool.submitTask(sum2, 1 ,2, 3);
   submitTask:可变参模板编程

2. 前版造了一个Result以及相关的类型，代码更多
    C++11 线程库   thread   packaged_task(function函数对象)  async
   使用future来代替Result节省线程池代码
*/

int sum1(int a, int b)
{
    this_thread::sleep_for(chrono::seconds(2));
    // 比较耗时
    return a + b;
}
int sum2(int a, int b, int c)
{
    this_thread::sleep_for(chrono::seconds(2));
    return a + b + c;
}
int main()
{
    ThreadPool pool;
    pool.start(4);

    future<int> r1 = pool.submitTask(sum1, 1, 2);

    cout << r1.get() << endl;

    // packaged_task<int(int, int)> task(sum1); // 包装函数
    // future<int> res = task.get_future();     // 保存函数的返回值
    // // task(10, 20);
    // thread t(move(task), 10, 20);

    // cout << res.get() << endl;
    // thread t1(sum1, 10, 20);
    // thread t2(sum2, 1, 2, 3);

    // t1.join();
    // t2.join();

    getchar();
    return 0;
}