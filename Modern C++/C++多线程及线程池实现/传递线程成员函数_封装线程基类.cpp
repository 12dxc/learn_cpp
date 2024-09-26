#include <iostream>
#include <thread>
using namespace std;

// 用成员函数作为入口函数

class MyThread
{
public:
    // 入口线程函数
    void Main()
    {
        cout << "MyThread Main " << name << " : " << age;
    }
    string name = "";
    int age = 100;
};
// 封装线程基类接口，更注重实现逻辑，而非创销线程
class XThread
{
public:
    virtual void Start()
    {
        is_exit = false;
        th_ = std::thread(XThread::Main, this);
    }
    void Stop()
    {
        is_exit = true;
        Wait();
    }
    virtual void Wait()
    {
        if (th_.joinable())
            th_.join();
    }
    bool get_isExit() { return is_exit; }

private:
    virtual void Main() = 0; // 要继承类必须实现线程入口函数
    std::thread th_;
    bool is_exit = false;
};
class TestXThread : public XThread
{
public:
    void Main() override
    {
        cout << "TestXThread Main Begin" << endl;
        while (!get_isExit())
        {
            this_thread::sleep_for(100ms);
            cout << "." << flush;
        }
        cout << "TestXThread Main End" << endl;
    }
    string name;
};
int main()
{
    // 使用局部函数初始化线程
    // thread th(&MyThread::Main, &myTh);
    // th.join();

    TestXThread testTh;
    testTh.name = "TestXThread name";
    testTh.Start();
    this_thread::sleep_for(3s);
    testTh.Stop();
    testTh.Wait();

    MyThread myTh;
    myTh.name = "test name 001";
    myTh.age = 20;

    return 0;
}