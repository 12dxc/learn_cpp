#pragma once
#include <iostream>
using namespace std;

class Singleton
{
public:
    // 一个全局使用的类频繁地创建与销毁
    static const Singleton *getinstance();
    static void DoSomething()
    {
        cout << "Do Something" << endl;
    }
    // 构造函数是私有的
private:
    Singleton();
    ~Singleton();

    // 确保一个类只有一个实例，并提供了一个全局访问点来访问该实例
    static Singleton *This;
};
