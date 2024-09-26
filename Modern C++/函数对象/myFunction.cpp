#include <iostream>
#include <functional>
using namespace std;

// 使用变参模板实现不限参数的函数对象包装器，即function类

// 需一个主模板
template <typename Fty>
class MyFunction
{
};

// 实现函数对象，用于包装函数，抽象为类型，具有与函数相同功能
template <typename R, typename... Args> // 类型1为返回值，2为所传参数
class MyFunction<R(Args...)>
{
public:
    using PFUNC = R (*)(Args...); // 创建函数指针类型
    MyFunction(PFUNC pfunc) : pfunc_(pfunc) {}
    // 重载()并调用函数指针
    R operator()(Args... args)
    {
        return pfunc_(args...);
    }

private:
    PFUNC pfunc_; // 存所传函数
};

int sum(int a, int b)
{
    return a + b;
}
int main()
{
    MyFunction<int(int, int)> func(sum);
    cout << func(10, 20) << endl;

    return 0;
}