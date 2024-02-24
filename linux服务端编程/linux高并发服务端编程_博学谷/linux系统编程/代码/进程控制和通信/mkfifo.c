#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int ret = -1;
    // 创建有名管道
    ret = mkfifo("fifo", 0644); // 参数1 文件路径，参数2 文件权限
    if (-1 == ret)
    {
        perror("mkfifo");
        return 1;
    }

    return 0;
}