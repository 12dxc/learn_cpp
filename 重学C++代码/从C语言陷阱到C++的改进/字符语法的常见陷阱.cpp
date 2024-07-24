#include <iostream>
#include <string>
using namespace std;

int main()
{
    char c1 = 'yes'; // 截断：保留最后一个字符
    // char c2 = "yes";   //超出了char的大小，故报错
    cout << c1 << endl;

    const char *slash = "/"; //-->'/','\0'
    // const char*slash='/';   //字符类型不能赋给字符指针
    const char *slash2 = &c1;
    cout << *slash2 << endl;

    string s1(1, 'yes');
    cout << s1 << endl; // s
    string s2(3, 'yes');
    cout << s2 << endl; // sss
    string s3(1, 'y');
    cout << s3 << endl; // y
    string s4(1, '/');  // /
    cout << s4 << endl;
    string s5("yes"); // yes
    cout << s5 << endl;

    return 0;
}