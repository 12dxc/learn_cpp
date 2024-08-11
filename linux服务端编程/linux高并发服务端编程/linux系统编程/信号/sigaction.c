#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// 信号处理函数
void fun(int signo)
{
    printf("捕捉到信号%d\n", signo);
}
// 新的信号处理函数
void fun1(int signo, siginfo_t *info, void *context)
{
    printf("捕捉到信号%d\n", signo);
}

// sigaction的使用
int main()
{
    int ret = -1;
#if 0
    struct sigaction act; // 要设置的对信号的处理方式
    // 使用旧的信号处理函数的指针
    act.sa_handler = fun;
    // 标志为默认 默认使用就的信号处理函数指针
    act.sa_flags = 0;  //标志用于指定信号处理的行为

#else
    // 需传递少量信息可用新版
    struct sigaction act;
    // 使用新的信号处理函数的指针
    act.sa_sigaction = fun1;
    // 标志指定使用就的信号处理函数指针
    act.sa_flags = SA_SIGINFO;

#endif
    // 信号注册
    ret = sigaction(SIGINT, &act, NULL);
    if (-1 == ret)
    {
        perror("sigaction");
        return 1;
    }

    printf("按下任意键退出...\n");
    getchar();

    return 0;
}