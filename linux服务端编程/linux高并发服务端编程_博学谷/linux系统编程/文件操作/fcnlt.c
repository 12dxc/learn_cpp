#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <unistd.h>

// fcntl复制文件描述符的功能
int main()
{
    int fd = -1;
    int newfd = -1;
    // 1、打开文件
    fd = open("txt", O_WRONLY | O_CREAT, 0644);
    if (-1 == fd)
    {
        perror("open");
        return 1;
    }
    printf("fd = %d\n", fd);

    // 2、文件描述符复制
    // 功能等于dup函数
    // 第三个参数0,表示返回一个最小的可用的文件描述符，并且大于或者等于0
    newfd = fcntl(fd, F_DUPFD, 0);
    if (-1 == newfd)
    {
        perror("fcntl");
        return 1;
    }
    printf("newfd = %d\n", newfd);

    // 3、写操作
    write(fd, "123456789", 9);
    write(newfd, "ABCDEFGH", 8);

    // 4、关闭文件
    close(fd);
    close(newfd);

    return 0;
}