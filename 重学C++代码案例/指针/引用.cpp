#include <iostream>
#include<memory>
#include<string>
#include<assert.h>     //断言
using namespace std;
/*
    引用：本质还是指针，是不允许修改的指针
    引用的优点：
        1、不存在空引用
        2、必须初始化
        3、一个引用永远指向初始化的那个对象
*/

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int x = 1, x2 = 3;
    int& rx = x;
    rx = 2;
    cout << x << endl;
    cout << rx << endl;
    rx = x2;
    cout << x << endl;
    cout << rx << endl;

    int a = 3, b = 4;
    swap(a, b);
    assert(a == 4 && b == 3);

    /*
        有了指针为什么还需要引用？
           为了支持函数运算符重载；
        有了引用为什么还需要指针？
           为了兼容C语言；
    */

    system("pause");
    return 0;
}