#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

// 创建守护进程
int main()
{
    int ret = -1;
    pid_t pid = -1;
    // 1、创建子进程  父进程退出
    pid = fork();
    if (-1 == pid)
    {
        perror("fork");
        return 1;
    }

    if (pid > 0)
    {
        // 父进程退出
        exit(0);
    }

    // 2、创建新的会话  完全脱离控制终端
    pid = setsid();
    if (-1 == pid)
    {
        perror("setsid");
        return 1;
    }

    // 3、改变当前的工作目录
    ret = chdir("/");
    if (-1 == ret)
    {
        perror("chdir");
        return 1;
    }

    // 4、设置权限掩码
    umask(0);

    // 5、关闭文件描述符
    close(STDIN_FILENO); // stdin --> FIFE *
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    // 6、执行核心的任务
    // 每个一秒输出当前时间至/tmp/txt.log文件中
    while (1)
    {
        system("date >> /tmp/txt.log");
        sleep(1);
    }

    return 0;
}