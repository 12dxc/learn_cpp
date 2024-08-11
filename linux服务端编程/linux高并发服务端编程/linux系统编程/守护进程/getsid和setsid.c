#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t pid = -1;
    pid = getsid(0); // 获取进程所属的会话ID
    if (-1 == pid)
    {
        perror("getsid");
        return 1;
    }
    printf("sid: %d\n", pid);

    // 新建一个会话
    pid = setsid(); // 组长进程不能成为新会话首进程
    if (-1 == pid)
    {
        perror("setsid");
        return 1;
    }
    printf("sid: %d\n", pid);

    return 0;
}