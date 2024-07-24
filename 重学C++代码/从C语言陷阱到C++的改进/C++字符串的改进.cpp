#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "str1:" << endl;
    string str1 = "string";
    cout << str1.length() << endl;
    cout << str1.capacity() << endl;
    cout << sizeof(str1) << endl;

    cout << "str2:" << endl;
    string str2 = "stri\0ng"; // string容器仍然可以用'\0'作为字符串结尾
    cout << str2.length() << endl;
    cout << str2.capacity() << endl;
    cout << sizeof(str2) << endl;

    cout << "str1 + str2:" << endl; // 相较于C，C++拼接无需考虑溢出问题
    str1 += str2;
    cout << str1.length() << endl;
    cout << str1.capacity() << endl;
    cout << sizeof(str1) << endl;

    return 0;
}