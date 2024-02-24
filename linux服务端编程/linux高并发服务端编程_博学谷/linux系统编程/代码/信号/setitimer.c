#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// 定时器定时退出
int main()
{
    int ret = -1;
    struct itimerval tmo; // 定时时间结构体，内包含触发时间、触发周期

    // 第一次触发时间
    tmo.it_value.tv_sec = 3;  // tv_sec 秒
    tmo.it_value.tv_usec = 0; // tv_usec 微秒

    // 触发周期
    tmo.it_interval.tv_sec = 2;
    tmo.it_interval.tv_usec = 0;

    // 设置定时器 参数分别为：定时方式 定时时间 存放旧定时时间（一般为空）
    ret = setitimer(ITIMER_REAL, &tmo, NULL);
    if (-1 == ret)
    {
        perror("setitimer");
        return 1;
    }

    // 进程收到定时器超时信号之后就会终止该进程
    printf("按任意键退出...\n");
    getchar();

    return 0;
}