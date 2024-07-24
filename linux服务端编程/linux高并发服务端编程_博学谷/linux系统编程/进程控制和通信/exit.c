#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    printf("hello world");
    // 等价于return 0
    // exit(0); // 标准库函数

    // 直接退出，不做任何清理工作
    //  _exit(0); // 系统调用函数

    // 等价于 _exit(0)
    _Exit(0); // 标准库函数

    // return 0;
}