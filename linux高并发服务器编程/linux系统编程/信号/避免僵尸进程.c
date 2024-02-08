#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <wait.h>

void sig_child(int signo)
{
    printf("捕捉到信号%d\n", signo);

    // 处理僵尸进程, -1 代表等待任意一个子进程, WNOHANG代表不阻塞
    while (waitpid(-1, NULL, WNOHANG) > 0)
    {
        printf("子进程退出了...\n");
    }
}

// 使用信号捕捉避免僵尸进程
int main()
{
    pid_t pid = -1;

    struct sigaction act;

    act.sa_handler = sig_child;
    act.sa_flags = 0;

    // 注册信号处理函数，捕捉子进程退出的信号并处理
    sigaction(SIGCHLD, &act, NULL);

    // 创建一个子进程
    pid = fork();
    if (-1 == pid)
    {
        perror("fork");
        return 1;
    }

    if (0 == pid)
    {
        // 子进程
        printf("子进程比较累，先休息两秒...\n");
        sleep(2);
        printf("子进程休息好了，太无聊了，就退出了...\n");

        exit(0);
    }
    else
    {
        // 父进程
        while (1)
        {
            printf("父进程工作中...\n");
            sleep(1);
        }
    }
}