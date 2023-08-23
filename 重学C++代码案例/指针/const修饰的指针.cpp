#include <iostream>
using namespace std;

int main()
{
    char strHelloworld[] = {"helloworld"};
    // const修饰的指针
    // 关于修饰的部分：看左侧最近的部分，如果没有，则看右侧

    // const修饰类型，指向值不可变
    char const *pStr1 = "helloworld"; // 注：const char 和 char const 等价
    // const修饰指针，指向不可变
    char *const pStr2 = strHelloworld;
    // 同时修饰类型和指针，指向和指向的值皆不可被更改
    char const *const pStr3 = "helloworld";

    pStr1 = strHelloworld;
    // pStr2 = strHelloworld; // pStr2不可改 程序报错
    // pStr3 = strHelloworld; // pStr3不可改 程序报错

    // pStr1[0] += 1;  //pStr1值不可改 程序报错
    pStr2[0] += 1;
    // pStr3[0] += 1;  //pStr3值不可改 程序报错

    return 0;
}