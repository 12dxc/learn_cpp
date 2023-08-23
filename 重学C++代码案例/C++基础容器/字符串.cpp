#include <iostream>
using namespace std;

int main()
{
    // 字符数组
    char strHelloWorld[] = {"helloWorld"}; // 数组本身不可以改变，但索引str[index]的值可以改变

    char c1 = 0;    // 00  二进制0
    char c2 = '\0'; // 00 占位
    char c3 = '0';  // 0x30  字符0

    cout << int(c3) << endl; // ASCII码，48

    // 字符指针
    const char *pStrHelloWorld = "helloWorld"; // 能否取决于指向的值能否更改

    cout << &("helloWorld") << endl; // 打印常量地址
    cout << pStrHelloWorld << endl;

    // 更改字符数组
    for (int i = 0; i < 10; i++)
    {
        strHelloWorld[i] += 1;
        cout << strHelloWorld[i];
    }

    return 0;
}