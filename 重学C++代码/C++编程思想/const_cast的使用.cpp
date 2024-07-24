#include <iostream>
using namespace std;

/*
 * C类型转换
 *   隐式类型转换：
 *       比如： double f = 1.0/2;
 *   显式类型转换：
 *       (类型说明符)(表达式)
 *       比如： double f = double(1)/double(2);
 * C类型转换的问题：
 *   1、任意类型之间都可以转换，编译器无法判断其正确性；
 *   2、难以定位：在源码中无法快速定位到错误；
 */

int main()
{
    // C++ const_cast 去常类型转换  用于转换指针或引用，去掉类型的const属性
    const int a = 10;
    // int* pA = &a;
    int *pA = const_cast<int *>(&a);
    *pA = 100;

    system("pause");
    return 0;
}