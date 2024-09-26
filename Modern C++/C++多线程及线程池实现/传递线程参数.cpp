#include <iostream>
#include <thread>
using namespace std;

// 为线程传递参数

class Para
{
public:
    Para() { cout << "Create Para" << endl; }
    Para(const Para &p) { cout << "Cope Para" << endl; }
    ~Para() { cout << "Drop Para" << endl; }
    string name;
};

void ThreadMain(int p1, float p2, string str, Para p4)
{
    cout << "ThreadMain " << p1 << " " << p2
         << " " << str << " " << p4.name << endl;
}
void ThreadMainPtr(Para *p)
{
    this_thread::sleep_for(1000ms);
    cout << "ThreadMainPtr name = " << p->name << endl;
}
void ThreadMainRef(Para &p)
{
    this_thread::sleep_for(1000ms);
    cout << "ThreadMainRef name = " << p.name << endl;
}
int main()
{
    {
        // 传递线程引用参数，不做复制
        Para p;
        p.name = "test ref";
        thread th(ThreadMainRef, ref(p)); // 模板无法区分引用参数，故加ref标识
        // th.detach(); // 会错误，线程访问p的空间会被提前释放
        th.join();
    }
    {
        // 传递线程指针参数，不做复制
        Para p;
        p.name = "test ptr";
        thread th(ThreadMainPtr, &p);
        th.detach(); // 会错误，线程访问p的空间会被提前释放
        // th.join();
    }
    // Para 释放

    // 传递线程普通参数，所有的参数作复制
    float f1 = 12.1f;
    Para pa;
    pa.name = "test Para class"; // 对象发生三次拷贝
    thread th(ThreadMain, 101, f1, "test string", pa);

    th.join();
    return 0;
}