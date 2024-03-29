#include <iostream>
#include <thread>
using namespace std;

// lambda临时函数，作为线程入口函数

class TestLambda
{
public:
    void Start()
    {
        thread th([this]()
                  { cout << "name = " << name << endl; });
        // th.detach();  //资源提前释放无法访问
        th.join();
    }

    string name = "test lambda";
};

int main()
{
    // 使用lambda简化线程作简单操作的情况
    thread th([](int i)
              { cout << "test lambda" << i << endl; },
              123);
    th.join();

    TestLambda tl;
    tl.Start();

    return 0;
}