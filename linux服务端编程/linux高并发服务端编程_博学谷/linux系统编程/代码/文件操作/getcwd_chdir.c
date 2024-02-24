#include <stdio.h>
#include <sys/fcntl.h>
#include <sys/types.h>
#include <unistd.h>

#define SIZE 32

int main()
{
    int ret = -1;
    char buf[SIZE];

    // 1、获取当前进程的工作目录
    if (NULL == getcwd(buf, SIZE))
    {
        perror("getcwd");
        return 1;
    }
    printf("buf: %s\n", buf);

    // 2、改变当前进程工作目录
    ret = chdir("/home/cong");
    if (-1 == ret)
    {
        perror("chdir");
        return 1;
    }

    // 3、获取当前进程的工作目录
    if (NULL == getcwd(buf, SIZE))
    {
        perror("getcwd");
        return 1;
    }
    printf("buf: %s\n", buf);

    return 0;
}