#include <iostream>
using namespace std;
#include <string>

// 字符串 插入和删除

void test01()
{
    string str = "hello";

    // 插入
    str.insert(1, "111");

    cout << "str = " << str << endl; // h111ello

    // 删除
    str.erase(1, 3);
    cout << "str = " << str << endl; // hello
}

int main()
{
    test01();

    system("pause");
    return 0;
}