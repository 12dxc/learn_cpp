#include <iostream>
using namespace std;
#include<math.h>

/*
函数的所有组成部分：
    1、返回类型：一个函数可以返回一个值
    2、函数名称：这是函数的实际名称，函数名和参数列表一起构成了函数签名
    3、参数：参数列表包括函数参数的类型、顺序、数量。参数是可选的
*/

//overload
int test(int a)
{
    return a;
}
int test(double a)
{
    return a;
}
int test(int a, double b)
{
    return a + b;
}

int main()
{
    //函数指针  每一个函数都占用一段内存单元，它们有一个起始地址，指向函数入口地址的指针称为函数指针
    //一般形式：数据类型 (*指针变量名)(参数表);
    int(*p)(int);
    p = test;

    //注意：指向函数的指针 返回指针的函数之间的区别
    //int (*p)(int); //是指针，指向一个函数入口地址
    //int* p(int);   //是函数，返回的值是一个指针

    //overload
    int result = (*p)(1);  // 间接调用test(int a);
    result = test(2.0);
    result = test(1, 2.0);


    system("pause");
    return 0;
}