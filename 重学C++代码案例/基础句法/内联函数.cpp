#include <iostream>
using namespace std;

//内联函数是一种特殊的函数，它在编译时会被嵌入到调用它的代码中，从而避免了函数调用的开销。
//内联函数可以提高程序的执行速度，但会增加代码的大小。即空间换时间
inline int maxValue(int a, int b)  //定义内联函数，需要在函数定义时加上 inline 函数修饰符
{
    return (a > b) ? a : b;
}

//递归函数
inline int Fib(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else {
        return Fib(n - 1) + Fib(n - 2);
    }
}

int main()
{
    int x = 3, y = 4;
    maxValue(x, y);

    Fib(5);   //递归不适合使用内联函数

    system("pause");
    return 0;
}