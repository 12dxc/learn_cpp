#include <iostream>
#include<memory>
#include<string>
using namespace std;

struct B;
struct A
{
    shared_ptr<B> pd;
    ~A()
    {
        cout << "~A()" << endl;
    }
};
struct B
{
    shared_ptr<A> pa;
    ~B()
    {
        cout << "~B()" << endl;
    }
};
//pa和pb存在循环引用，根据shared_ptr的引用计数原理，pa和pd都无法被正常的释放
//weak_ptr是为了解决shared_ptr双向引用的问题

struct BW;
struct AW
{
    shared_ptr<BW> pd;
    ~AW()
    {
        cout << "~AW()" << endl;
    }
};
struct BW
{
    weak_ptr<AW> pa;
    ~BW()
    {
        cout << "~BW()" << endl;
    }
};

void test1()
{
    cout << "shared_ptr 和 shared_ptr 的输出" << endl;
    shared_ptr<A>tA(new A());
    shared_ptr<B>tB(new B());
    cout << tA.use_count() << endl;   // 1
    cout << tB.use_count() << endl;   // 1
    tA->pd = tB;
    tB->pa = tA;
    cout << tA.use_count() << endl;    // 2
    cout << tB.use_count() << endl;    // 2 

}
void test2()
{
    cout << "shared_ptr 和 shared_ptr 的输出" << endl;
    shared_ptr<AW>tA(new AW());
    shared_ptr<BW>tB(new BW());
    cout << tA.use_count() << endl;    // 1
    cout << tB.use_count() << endl;    // 1
    tA->pd = tB;
    tB->pa = tA;
    cout << tA.use_count() << endl;     // 1
    cout << tB.use_count() << endl;     // 2
    //weak_ptr不参与在计数
}

int main()
{
    test1();
    test2();

    system("pause");
    return 0;
}