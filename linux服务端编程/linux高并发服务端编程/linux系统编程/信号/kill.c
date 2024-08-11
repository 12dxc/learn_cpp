#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

// 父进程杀死子进程
int main()
{
    pid_t pid = -1;
    pid = fork();
    if (-1 == pid)
    {
        perror("fork");
        return 1;
    }

    if (pid == 0)
    {
        // 子进程
        while (1)
        {
            printf("子进程正在工作...\n");
            sleep(1);
        }

        exit(0);
    }
    else
    {
        // 父进程
        sleep(3);
        printf("子进程不听话了，该退出了...\n");
        // kill()  给指定进程发送指定信号
        kill(pid, 15);
        printf("父进程该结束了，已完成他的使命\n");
    }

    return 0;
}