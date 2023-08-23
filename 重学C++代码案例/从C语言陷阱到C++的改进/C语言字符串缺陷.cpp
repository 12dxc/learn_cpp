#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    // '\0'结束符，表达能力的天生缺陷,运行效率低
    char str1[] = "string";
    cout << strlen(str1) << endl; // 6
    cout << sizeof(str1) << endl; // 7 字符数组会在末位加'/0'

    char str2[] = "str\0ing";
    cout << strlen(str2) << endl; // 3   '\0'是一个串的结尾，所以此字符串被截断为3
    cout << sizeof(str2) << endl; // 8

    char str1A[30] = "stringA";
    strcat(str1A, str2);           // 字符串拼接 原始空间一定要 > 原字符串+拼接字符串的总长度
    cout << str1A << endl;         // stringAstr
    cout << strlen(str1A) << endl; // 10

    return 0;
}