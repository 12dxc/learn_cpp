#include <iostream>
using namespace std;
#include"String.h"


int main()
{
    String s1("hello");    //构造函数
    cout << s1 << endl;
    String s2(s1);         //拷贝构造
    cout << s2 << endl;

    system("pause");
    return 0;
}

