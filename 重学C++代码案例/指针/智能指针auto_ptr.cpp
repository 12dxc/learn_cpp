#include <iostream>
#include<memory>
#include<string>
using namespace std;


int main()
{
    {
        //对int使用
        auto_ptr<int> pl(new int(10));
        cout << *pl << endl;      //10

        //auto_ptr 在C++17中移除
        //auto_ptr原理：在拷贝/赋值过程中，直接剥夺原对象对内存的控制权，转交给新对象
        //然后在将原对象指针置为nullptr，这种做法也叫管理权转移
        //缺点：当再去访问原对象时，程序就会报错

        auto_ptr<string> languages[5] = {
            auto_ptr<string>(new string("C")),
            auto_ptr<string>(new string("Java")),
            auto_ptr<string>(new string("Python")),
            auto_ptr<string>(new string("C++")),
            auto_ptr<string>(new string("PHP")),
        };
        for (int i = 0; i < 5; i++)
        {
            cout << *languages[i] << endl;
        }

        auto_ptr<string>pC;
        pC = languages[2];  //languages[2]将所有权转让给pC
        //此时languages[2]不在引用该字符串从而变为空指针
        cout << "权限让渡后" << endl;
        for (int i = 0; i < 2; i++)
        {
            cout << *languages[i] << endl;
        }
        //cout << "第三次打印" << endl;
        //for (int i = 0; i < 5; i++)    //auto_ptr所指的信息不存在了，所以无法输出；报异常，之后的也无法打印
        //{
        //    cout << *languages[i] << endl;  //C Java
        //}
    }
    //当auto_ptr出了作用域，会直接释放掉所指向的对象

    return 0;
}