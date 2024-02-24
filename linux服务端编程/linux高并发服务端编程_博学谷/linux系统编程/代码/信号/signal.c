#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// 信号处理函数
void fun1(int signum)
{
    printf("捕捉到信号%d\n", signum);
}
void fun2(int signum)
{
    printf("捕捉到信号%d\n", signum);
}

// 信号注册函数
int main()
{
    // 信号注册
    // Ctrl + C
    signal(SIGINT, fun1);

    // Ctrl + \   占位
    signal(SIGQUIT, fun2);

    getchar();

    return 0;
}