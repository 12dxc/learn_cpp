#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// 在指定时间杀死当前进程
int main()
{
    unsigned int ret = 0;

    // 第一次设置闹钟  5秒后发送指定信号
    ret = alarm(5); // 设置闹钟，在到达指定时间（即参数）后，给自己发送信号14
    printf("上一个闹钟剩下的时间为%u\n", ret);

    sleep(2);

    // 第二次设置闹钟  覆盖之前未超时的闹钟
    ret = alarm(3);
    printf("上一个闹钟剩下的时间为%u\n", ret);

    printf("按任意键退出...\n");
    getchar();

    return 0;
}