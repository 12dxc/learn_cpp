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

// 修改当前进程的信号阻塞集
int main()
{
    sigset_t set, oldset; // 信号集

    // 信号注册
    // Ctrl + C
    signal(SIGINT, fun1);

    // Ctrl + \   占位
    signal(SIGQUIT, fun2);

    printf("按下回车键，屏蔽信号2...\n");
    getchar();

    // 置空信号集
    sigemptyset(&set);
    sigemptyset(&oldset);

    sigaddset(&set, SIGINT); // 编号2的信号加入信号集

    // 设置屏蔽编号2的信号
    sigprocmask(SIG_BLOCK, &set, &oldset); // 此函数可修改当前进程的信号阻塞集
    printf("设置屏蔽编号2的信号成功...\n");

    printf("按下回车键解除屏蔽\n");
    getchar();

    // 还原信号屏蔽集
    sigprocmask(SIG_SETMASK, &oldset, NULL);

    printf("按下回车键退出...\n");
    getchar();

    return 0;
}