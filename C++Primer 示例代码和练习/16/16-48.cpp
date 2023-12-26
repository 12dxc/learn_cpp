#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// 打印任何不能处理的类型

// 最通用版本
template <typename T>
string debug_rep(const T &t)
{
    ostringstream ret;
    ret << t;         // 使用T的输出运算符打印t的一个表示形式
    return ret.str(); // 返回ret绑定的string的一个副本
}
// 指针版本
template <typename T>
string debug_rep(T *p)
{ // 打印指针的值，后跟指针指向的对象
    ostringstream ret;
    ret << "pointer: " << p; // 打印指针本身的值
    if (p)
        ret << " " << debug_rep(*p); // 打印p指向的值
    else
        ret << " null pointer"; // 或指出指针为空
    return ret.str();           // 返回ret绑定的string的一个副本
}
// 非模板版本
string debug_rep(const string &s)
{
    return '"' + s + '"';
}
// 处理字符指针，将其转为string 的非模板版本
string debug_rep(char *p)
{
    return debug_rep(string(p));
}
string debug_rep(const char *p)
{
    return debug_rep(string(p));
}

int main()
{
    string s("hi");
    cout << debug_rep(s) << endl;
    cout << debug_rep(&s) << endl;

    system("pause");
    return 0;
}