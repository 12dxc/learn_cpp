#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// 读文件
int main()
{
    int fd = -1;  // 记录open返回值
    int ret = -1; // 记录close返回值

    char buf[1024] = "";

    // 1、以只读的方式打开一个文件
    fd = open("txt", O_RDONLY | O_CREAT, 0644);
    if (-1 == fd)
    {
        perror("open");
        return 1;
    }
    printf("fd = %d\n", fd);

    // 2、读文件
    ret = read(fd, buf, 1024);
    if (-1 == ret)
    {
        perror("read");
        return 1;
    }
    printf("read len: %d str: %s\n", ret, buf);

    // 3、关闭文件
    close(fd);

    return 0;
}