#include <iostream>
#include <string>
using namespace std;
/*
    string结合了C++的新特性,
    使用起来比原始的C风格字符串更安全和方便,
    对性能要求不是特别高的可以使用。
*/

int main()
{
    string s1;
    s1 = "hello wolrd";

    // C++的字符串，内部存有长度
    cout << s1.length() << endl;

    // C++的字符串可以直接通过比较运算符，来进行比较
    string s2 = "abcdefg";
    cout << "s1 > s2 = " << (s1 > s2) << endl;

    // 转换为C风格字符串 c_str()

    // 字符串拷贝，可直接使用赋值运算符 "="
    string s3;
    cout << (s3 = s2) << endl;

    // 字符串拼接，可直接使用加法运算符 "+"、"+="
    cout << "s1 + s2 = " << (s1 + s2) << endl;

    return 0;
}