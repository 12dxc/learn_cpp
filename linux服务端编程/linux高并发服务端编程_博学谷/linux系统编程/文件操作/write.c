#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// 写文件
int main()
{
    int fd = -1;  // 记录open返回值
    int ret = -1; // 记录close返回值

    char *str = "hello world";

    // 1、以只写的方式打开一个文件
    fd = open("txt", O_WRONLY | O_CREAT, 0644);
    if (-1 == fd)
    {
        perror("open");
        return 1;
    }
    printf("fd = %d\n", fd);

    // 2、写文件
    ret = write(fd, str, strlen(str));
    if (-1 == ret)
    {
        perror("write");
        return 1;
    }
    printf("write len: %d\n", ret);

    // 3、关闭文件
    close(fd);

    return 0;
}