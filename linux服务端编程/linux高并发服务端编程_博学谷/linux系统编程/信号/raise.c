#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

// 自己给自己发送信号
int main()
{
    int i = 0;
    while (1)
    {
        printf("%d-工作中...\n", i);
        if (4 == i)
        {
            // raise()  给当前进程发送指定信号
            // 等价于kill(getpid(),SIGTERM);
            raise(SIGTERM);
        }
        ++i;
        sleep(1);
    }

    return 0;
}