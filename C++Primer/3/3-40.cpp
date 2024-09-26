#include <iostream>
#include <cstring>
using namespace std;

const char cstr1[] = "hello";
const char cstr2[] = "world";

int main()
{
    char largeStr[20];
    // 将第一个数组的内容copy给第三个数组
    strcpy(largeStr, cstr1);
    // 给第三个数组加一个空格
    strcat(largeStr, " ");
    // 将第二个数组附给第三个数组
    strcat(largeStr, cstr2);

    return 0;
}
