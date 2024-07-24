#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// 互斥锁变量
pthread_mutex_t mutex;

void *fun1(void *arg)
{
    // 加锁
    pthread_mutex_lock(&mutex);
    for (int i = 'A'; i <= 'Z'; ++i)
    {
        putchar(i);
        usleep(100000); // 100ms
    }
    // 解锁
    pthread_mutex_unlock(&mutex);
}
void *fun2(void *arg)
{
    // 加锁
    pthread_mutex_lock(&mutex);
    for (int i = 'a'; i <= 'z'; ++i)
    {
        putchar(i);
        usleep(100000);
    }
    // 解锁
    pthread_mutex_unlock(&mutex);
}
// 模拟输出字符
int main()
{
    int ret = -1;
    pthread_t tid1 = -1, tid2 = -1;

    // 创建互斥锁/量
    pthread_mutex_init(&mutex, NULL);
    if (0 != ret)
    {
        printf("pthread_mutex_init failed...\n");
        return 1;
    }

    // 创建两个线程
    pthread_create(&tid1, NULL, fun1, NULL);
    pthread_create(&tid2, NULL, fun2, NULL);

    // 等待两个线程结束
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    putchar('\n');
    printf("main thread exit...\n");

    // 销毁互斥锁/量
    pthread_mutex_destroy(&mutex);

    return 0;
}