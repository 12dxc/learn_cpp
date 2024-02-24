#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

int main()
{
    int i = 0;
    while (1)
    {
        printf("%d-工作中...\n", i);
        if (4 == i)
        {
            // 给自己发送异常终止信号 即编号6的信号
            abort();
        }
        ++i;
        sleep(1);
    }

    return 0;
}