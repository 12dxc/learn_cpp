#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <wait.h>

// 等待子进程退出
int main()
{
    int status = 0; // 状态码
    int ret = -1;
    pid_t pid = -1;

    // 创建子进程
    pid = fork();
    if (-1 == pid)
    {
        perror("fork");
        return 1;
    }

    // 子进程
    if (0 == pid)
    {
        for (int i = 0; i != 5; ++i)
        {
            printf("子进程%d正在运行%d次\n", getpid(), i);
            sleep(1);
        }
        // 子进程终止
        exit(0);
    }

    // 父进程执行
    printf("父进程等待子进程退出，回收其资源\n");
    // 父进程阻塞，等待子进程退出
    // ret = wait(&status); // 参数为进程退出时的状态信息

    // 等价于wait()
    // ret = waitpid(-1, &status, 0);
    ret = waitpid(-1, &status, WNOHANG); // 参数3表示不阻塞
    if (-1 == ret)                       // 等待失败
    {
        perror("wait");
        return 1;
    }
    printf("父进程回收了子进程的资源\n");

    // 通过状态码获取进程退出信息
    // 属于正常退出
    if (WIFEXITED(status))
        printf("子进程退出状态码：%d\n", WEXITSTATUS(status)); // WEXITSTATUS 此返回值，即子进程的返回值
    // 异常终止
    else if (WIFSIGNALED(status))
        // kill 进程号  杀死指定进程
        printf("子进程被信号%d杀死了...\n", WTERMSIG(status));
    // 处于暂停状态
    else if (WIFSTOPPED(status))
        // kill -19 进程号  向指定进程发送暂停信号 | -18 为唤醒
        printf("子进程被%d暂停了...", WSTOPSIG(status));

    return 0;
}