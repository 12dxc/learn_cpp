#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

// 父子进程间通信
int main()
{
    int fds[2];
    int ret = -1;
    pid_t pid = -1;
    char buf[128];

    ret = pipe(fds);
    if (-1 == ret)
    {
        perror("pipe");
        return 1;
    }

    pid = fork();
    if (pid > 0)
    {
        // 子进程 读管道
        close(fds[1]); // 关闭写端

        printf("子进程读取管道的内容...\n");
        // 设置读端为非阻塞
        ret = fcntl(fds[0], F_GETFL);
        ret |= O_NONBLOCK;
        fcntl(fds[0], F_SETFL, ret);

        // 读文件
        ret = read(fds[0], buf, 128);
        if (-1 == ret)
        {
            perror("read");
            return 1;
        }
        printf("子进程读到的文件是：%s\n", buf);

        close(fds[0]); // 关闭读端
        exit(0);
    }

    // 父进程 写管道
    close(fds[0]); // 关闭读端

    sleep(1);
    // 写文件
    ret = write(fds[1], "ABCDEFG", 7);
    if (-1 == ret)
    {
        perror("write");
        return 1;
    }
    printf("父进程写入文件%d字符\n", 7);

    close(fds[1]); // 关闭写端

    return 0;
}