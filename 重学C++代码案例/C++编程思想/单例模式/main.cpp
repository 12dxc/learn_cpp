#include<iostream>
using namespace std;
#include "Singleton.h"

/*
单例模式：
    这种模式涉及到一个单一的类，该类负责创建自己的对象，同时确保只有单个对象被创建。
    这个类提供了一种访问其唯一的对象的方式，可以直接访问，不需要实例化该类的对象。
*/
int main()
{
    Singleton::getinstance()->DoSomething();

    system("pause");
    return 0;
}