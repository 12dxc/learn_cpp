#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    // pid  标识进程的一个非负整型数
    // 获取本进程号（PID）
    pid_t pid = getpid(); // 无参
    printf("当前进程号：%d\n", pid);

    // 获取调用此函数的进程的父进程号（PPID）
    pid = getppid(); // 无参
    printf("父进程号：%d\n", pid);

    // 获取进程组号（PGID）
    pid = __getpgid(getpid()); // 参数为进程号
    printf("进程组号：%d\n", pid);

    return 0;
}