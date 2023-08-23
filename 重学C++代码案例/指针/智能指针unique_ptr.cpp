#include <iostream>
#include<memory>
#include<string>
using namespace std;


int main()
{
    //在这个范围之内
    {
        auto i = unique_ptr<int>(new int(10));
        cout << *i << endl;
    }

    //unique_ptr
    auto w = make_unique<int>(10);
    cout << *(w.get()) << endl;   //10

    //auto w2 = w;  //unique_ptr 有专有权，不支持拷贝

    //unique_ptr 只支持移动语义 move()
    auto w2 = move(w);   //w2获得内存所有权，w此时等于nullptr
    cout << ((w.get() != nullptr) ? (*w.get()) : -1) << endl;  //-1
    cout << ((w2.get() != nullptr) ? (*w2.get()) : -1) << endl;   //10

    system("pause");
    return 0;
}