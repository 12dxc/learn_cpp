#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <unistd.h>

// fcntl设置和获取文件状态标志
int main()
{
    int fd = -1;
    int newfd = -1;
    int ret = -1;

    // 1、打开文件
    fd = open("txt", O_WRONLY | O_CREAT, 0644);
    if (-1 == fd)
    {
        perror("open");
        return 1;
    }
    printf("fd = %d\n", fd);

    // 2、获取文件状态标记
    ret = fcntl(fd, F_GETFL);
    if (-1 == ret)
    {
        perror("fcntl");
        return 1;
    }
    if (ret & O_APPEND)
    {
        printf("有append\n");
    }
    else
    {
        printf("没有append\n");
    }
    // 3、设置文件状态标记
    ret = ret | O_APPEND;
    ret = fcntl(fd, F_SETFL, ret);
    if (-1 == ret)
    {
        perror("fcntl");
        return 1;
    }
    // 4、获取文件状态标记
    ret = fcntl(fd, F_GETFL);
    if (-1 == ret)
    {
        perror("fcntl");
        return 1;
    }
    if (ret & O_APPEND)
    {
        printf("有append\n");
    }
    else
    {
        printf("没有append\n");
    }

    newfd = fcntl(fd, F_DUPFD, 0);
    if (-1 == newfd)
    {
        perror("fcntl");
        return 1;
    }
    printf("newfd = %d\n", newfd);

    // 5、关闭文件
    close(fd);
    close(newfd);

    return 0;
}