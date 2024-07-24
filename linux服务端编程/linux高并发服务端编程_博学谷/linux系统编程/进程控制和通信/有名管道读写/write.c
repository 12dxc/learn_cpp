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
    int i = 0;
    int fd = -1;
    int ret = -1;
    char buf[128];

    // 1、以只写的方式打开一个管道文件
    fd = open("fifo", O_WRONLY);
    if (-1 == fd)
    {
        perror("open");
        return 1;
    }
    printf("以只写方式打开一个管道文件ok...\n");

    // 2、写管道
    while (1)
    {
        memset(buf, 0, 128);
        sprintf(buf, "hello world %d", i++);
        ret = write(fd, buf, strlen(buf));
        if (ret <= 0)
        {
            perror("write");
            break;
        }
        printf("写管道：%d\n", ret);
        sleep(1);
    }

    // 3、关闭文件
    close(fd);
    return 0;
}