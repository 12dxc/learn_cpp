#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <unistd.h>

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
    printf("fd = %d", fd);

    // newfd = dup(fd);
    newfd = 2;
    // 可以指定文件描述符，如果已关联，则close文件，取消关联
    newfd = dup2(fd, newfd);
    if (-1 == newfd)
    {
        perror("dup");
        return 1;
    }
    printf("newfd = %d", newfd);

    // 2、操作文件
    // 两个操作符指向同一个文件表，则共享当前文件偏移量，故是追加，而非开头写入
    write(fd, "ABCDEFG", 7);
    write(newfd, "1234567", 7);

    // 3、关闭文件
    close(fd);
    close(newfd);

    return 0;
}