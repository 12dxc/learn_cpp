#include <iostream>
#include<memory>
#include<string>
using namespace std;

//shared_ptr通过一个引用计数共享一个对象
//shared_ptr是为了解决auto_ptr在对象所有权上的局限性
int main()
{
    //shared_ptr 代表的是共享所有权，即多个 shared_ptr可以共享一块内存
    auto wA = shared_ptr<int>(new int(20));
    {
        auto wA2 = wA;
        cout << ((wA2.get() != nullptr) ? (*wA2.get()) : -1) << endl;    //20
        cout << ((wA.get() != nullptr) ? (*wA.get()) : -1) << endl;      //20
        //use_count可返回指针所指向对象的引用数
        cout << wA2.use_count() << endl;     //2
        cout << wA.use_count() << endl;      //2

    }

    cout << wA.use_count() << endl;            //1
    cout << ((wA.get() != nullptr) ? (*wA.get()) : -1) << endl;    //20
    /* shared_ptr 内部是利用引用计数来实现内存的自动管理，没得复制一个 shared_ptr，
       引用计数会 +1，当一个 shared_ptr离开作用域是，引用计数会 -1.
       当引用计数为0时，则delete内存
    */


    //move语法
    auto wAA = make_shared<int>(30);
    auto wAA2 = move(wAA);  //此时wAA等于nullptr，wAA2.use_count()等于1
    cout << ((wAA.get() != nullptr) ? (*wAA.get()) : -1) << endl;  //-1
    cout << ((wAA2.get() != nullptr) ? (*wAA2.get()) : -1) << endl;  //30
    cout << wAA.use_count() << endl;              //0
    cout << wAA2.use_count() << endl;             //1
    //将wAA对象move给wAA2，意味着w放弃了堆内存的所有权和管理，此时wAA对象等于nullptr。
    //而wAA2获得了对象所有权，但因为此时wAA已不在持有对象，因此wAA2的引用计数为1。

    system("pause");
    return 0;
}