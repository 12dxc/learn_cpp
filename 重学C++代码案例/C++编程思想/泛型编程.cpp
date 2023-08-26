#include<iostream>
#include<cstring>
using namespace std;

/*
* 1、如果说面向对象是一种通过间接层来调用函数，以换取一种抽象，
*   那么泛型编程就是更直接的抽象，他不会因为间接层而损失效率；
* 2、不同于面向对象的动态期多态，泛型编程是一种静态期多态，通过编译器生成最直接的代码；
* 3、泛型编程可以直接将算法与特定类型，结构玻璃，尽可能复用代码。
*/

template<typename T>
T Max(T a, T b)
{
    return a > b ? a : b;
}
//特化
template<>
char* Max(char* a, char* b)
{
    return strcmp(a, b) > 0 ? (a) : (b);
}

//类型不确定，返回值确定; 这样的方法可分离数据结构与算法
template<typename T1, typename T2>
int Max(T1 a, T2 b)
{
    return static_cast<int>(a > b ? a : b);
}

int main()
{
    cout << Max(1, 2) << endl;
    cout << Max(1.5, 3.5) << endl;
    cout << Max('a', 'b') << endl;
    cout << Max("hello", "world") << endl;

    char* s1 = "hello";
    char* s2 = "world";
    cout << Max(s1, s2) << endl;

    cout << Max(10, 2.5) << endl;

    system("pause");
    return 0;
}