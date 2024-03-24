#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
#include "threadPool.h"

using ulong = unsigned long long;

// 给每一个线程分配计算的区间，并等待他们算完返回结果，合并最终的结果即可
class MyTask : public Task
{
public:
    MyTask(int begin, int end) : begin_(begin), end_(end) {}
    // 问题一：怎么设计run函数的返回值，可以表示任意的类型
    // 解决：C++17 Any类型，此处的为自实现
    Any run() // run方法最终就在线程池分配的线程中去做执行了
    {
        // cout << "tid:" << this_thread::get_id() << "begin!" << endl;
        this_thread::sleep_for(chrono::seconds(5));
        ulong sum = 0;
        for (ulong i = begin_; i <= end_; ++i)
            sum += i;
        // cout << "tid:" << this_thread::get_id() << "end!" << endl;

        return sum;
    }

private:
    int begin_;
    int end_;
};
int main()
{
    {
        ThreadPool pool;
        // 开始启动线程池
        pool.start(2, PoolMode::MODE_CACHED);

        // linux上，这些Result对象也是局部对象，要析构的！！！
        Result res1 = pool.submitTask(std::make_shared<MyTask>(1, 100000000));
        Result res2 = pool.submitTask(std::make_shared<MyTask>(100000001, 200000000));
        pool.submitTask(std::make_shared<MyTask>(100000001, 200000000));
        pool.submitTask(std::make_shared<MyTask>(100000001, 200000000));
        pool.submitTask(std::make_shared<MyTask>(100000001, 200000000));

        // uLong sum1 = res1.get().cast_<uLong>();
        // cout << sum1 << endl;
    } // 这里Result对象也要析构!!! 在vs下，条件变量析构会释放相应资源的

    cout << "main over!" << endl;

#if 0
    // 问题：ThreadPool对象析构以后，怎么样把线程池相关的线程资源全部回收？
    {
        ThreadPool pool;
        pool.start(4, PoolMode::MODE_CACHED); // 参数2为设置模式，可选

        // 如何设计这里的Result机制呢
        Result res1 = pool.submitTask(make_shared<MyTask>(1, 10000));
        Result res2 = pool.submitTask(make_shared<MyTask>(10001, 20000));
        Result res3 = pool.submitTask(make_shared<MyTask>(20001, 30000));
        pool.submitTask(make_shared<MyTask>(20001, 30000));
        pool.submitTask(make_shared<MyTask>(20001, 30000));

        // 跟着task被执行完，task对象没了，依赖于task对象的Result对象也没了
        ulong sum1 = res1.get().cast<ulong>(); // 返回了一个Any类型，怎么转为具体类型
        ulong sum2 = res2.get().cast<ulong>();
        ulong sum3 = res3.get().cast<ulong>();

        cout << (sum1 + sum2 + sum3) << endl;

        ulong sum = 0;
        for (ulong i = 1; i <= 30000; i++)
            sum += i;
        cout << sum << endl;
    }
#endif

    getchar();
    return 0;
}