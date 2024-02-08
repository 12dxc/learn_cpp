#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

// 写有名管道
int main()
{
    int fd = -1;
    int ret = -1;
    char buf[128];

    // 1、以只写的方式打开一个管道文件
    fd = open("fifo", O_RDONLY);
    if (-1 == fd)
    {
        perror("open");
        return 1;
    }
    printf("以只读方式打开一个管道文件ok...\n");

    // 2、读管道
    while (1)
    {
        memset(buf, 0, 128); // 重置字符数组
        ret = read(fd, buf, 128);
        if (ret <= 0)
        {
            perror("read");
            break;
        }
        printf("读管道：%s\n", buf);
    }

    // 3、关闭文件
    close(fd);

    return 0;
}