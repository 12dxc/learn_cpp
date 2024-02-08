#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// 第一个线程启动之后的任务
void *fun1(void *arg)
{
    printf("当前线程的线程号: %ld\n", pthread_self());
}
// 第二个线程启动之后的任务
void *fun2(void *arg)
{
    int var = (int)(long)arg;
    printf("线程2 var = %d\n", var);
}
int main()
{
    int ret = -1;
    pthread_t tid1 = -1, tid2 = -1;

    // 创建一个线程
    ret = pthread_create(&tid1, NULL, fun1, NULL);
    if (-1 == ret)
    {
        printf("线程创建失败...\n");
        return 1;
    }
    // 再创建一个线程
    ret = pthread_create(&tid2, NULL, fun2, (void *)0x3);
    if (-1 == ret)
    {
        printf("线程创建失败...\n");
        return 1;
    }

    printf("主线程的线程号: %ld\n", pthread_self());

    printf("按任意键主线程退出...\n");
    getchar();

    return 0;
}