#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

// 区分父子进程
int main()
{
    pid_t pid = -1;
    // 创建一个子进程
    pid = fork(); // fork函数在子进程中返回0  在父进程中返回子进程的pid
    if (pid < 0)
    {
        // 没有创建成功
        perror("fork");
        return 1;
    }

    if (0 == pid)
    {
        while (1)
        {
            // 子进程
            printf("子进程 pid: %d, ppid: %d\n", getpid(), getppid());
            sleep(1);
        }
    }
    else
    {
        while (1)
        {
            // 父进程
            printf("父进程 pid: %d, cpid: %d\n", getpid(), pid);
            sleep(1);
        }
    }
}