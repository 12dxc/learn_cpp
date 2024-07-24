#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// 打印当前信号集
void show_set(sigset_t *s)
{
    for (int i = 1; i < 32; ++i)
    {
        // 判断信号是否存在
        if (sigismember(s, i))
            printf("1");
        else
            printf("0");
    }
    putchar('\n');
}
// 信号集处理函数
int main()
{
    // 创建信号集集合
    sigset_t set; // 注：sigset_t非C标准，须在gnu标准下编译

    // 清空集合
    sigemptyset(&set);
    show_set(&set);

    // 将所有信号加入set集合
    sigfillset(&set);
    show_set(&set);

    // 将信号2、3从信号集中移除
    sigdelset(&set, SIGINT); // 移除信号
    sigdelset(&set, SIGQUIT);
    show_set(&set);

    // 将信号2添加到集合中
    sigaddset(&set, SIGINT); // 添加信号
    show_set(&set);

    return 0;
}