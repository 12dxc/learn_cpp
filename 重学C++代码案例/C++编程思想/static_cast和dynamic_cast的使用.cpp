#include<iostream>
using namespace std;

/*
* static_cast：
*   用于基本类型转换，有继承关系类对象和类指针之间转换，
*   由程序员来确保转换是安全的，它不会产生动态转换的类型安全检测的开销。
* dynamic_cast：
*   只能用于含有虚函数的类，必须用在多态体系中，用于类层次间的向上
*   和向下转化向下转换时，如果是非法的对于指针返回NULL。
*/

class Base
{
public:
    Base() :_i(0) { ; }
    virtual void T() { cout << "Base:T" << _i << endl; }
private:
    int _i;
};
//继承类
class Derived :public Base
{
public:
    Derived() :_j(1) { ; }
    virtual void T() { cout << "Derived:T" << _j << endl; }
private:
    int _j;
};

int main()
{
    //static_cast 静态类型转换 
    //源类型和目标类型只要有一个方向可以隐式转换，那么两个方向都可以做静态类型转换，如果不能则报错
    int i = 5;
    double d = static_cast<double> (i);
    double d2 = 5.6;
    int i2 = static_cast<int>(d2);

    Base cb;
    Derived cd;
    Base* pcb;
    Derived* pcd;
    //子类->父类
    pcb = static_cast<Base*>(&cd);
    //dynamic_cast 动态类型转换
    pcb = dynamic_cast<Base*>(&cd);
    if (pcb == NULL)   //dynamic_cast 可以检测是否转换成功，未成功会返回0
    {
        cout << "不能封装子类到父类" << endl;
    }

    //父类->子类
    pcd = static_cast<Derived*>(&cb);
    pcd = dynamic_cast<Derived*>(&cb);
    if (pcd == NULL)
    {
        cout << "不能封装父类到子类" << endl;
    }


    system("pause");
    return 0;
}