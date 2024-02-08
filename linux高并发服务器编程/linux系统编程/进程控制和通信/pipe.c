#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

// 创建无名管道
int main()
{
    int fds[2];
    int ret = -1;

    // 创建一个无名管道
    ret = pipe(fds);
    if (-1 == ret)
    {
        perror("pipe");
        return 1;
    }

    // fds[0]用于读  fds[1]用于写
    printf("fds[0]: %d  fds[1]: %d\n", fds[0], fds[1]);

    // 关闭文件描述符
    close(fds[1]);
    close(fds[0]);
}