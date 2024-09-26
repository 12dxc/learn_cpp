#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
    // 比较两个字符串
    // string
    string s1("hello");
    string s2("hello");
    if (s1 == s2)
    {
        cout << "两个字符串相等" << endl;
    }
    else
    {
        cout << "两个字符串不相等" << endl;
    }

    // C style string
    char a1[] = "hello";
    char a2[] = "hello";
    if (strcmp(a1, a2) == 0)
    {
        cout << "两个字符串相等" << endl;
    }
    else
    {
        cout << "两个字符串不相等" << endl;
    }

    return 0;
}
