#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// 查看管道缓冲区
int main()
{
    int fds[2];
    int ret = -1;
    ret = pipe(fds);
    if (-1 == ret)
    {
        perror("pipe");
        return 1;
    }

    // 参数2 _PC_PIPE_BUF 查看管道缓冲区大小 | _PC_NAME_MAX，文件名字字节数的上限
    long num = fpathconf(fds[0], _PC_PIPE_BUF); // 返回值为参2所求值

    printf("fds[0]缓冲区大小为：%ld\n", num);

    return 0;
}