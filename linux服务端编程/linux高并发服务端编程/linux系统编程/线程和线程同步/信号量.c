#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

// 信号量变量
sem_t sem;

void *fun1(void *arg)
{
    // 申请资源 将可用资源加1
    sem_wait(&sem);
    for (int i = 'A'; i <= 'Z'; ++i)
    {
        putchar(i);
        usleep(100000); // 100ms
    }
    // 释放资源 将可用资源减1
    sem_post(&sem);
}
void *fun2(void *arg)
{
    // 申请资源 将可用资源加1
    sem_wait(&sem);
    for (int i = 'a'; i <= 'z'; ++i)
    {
        putchar(i);
        usleep(100000);
    }
    // 释放资源 将可用资源减1
    sem_post(&sem);
}
// 模拟输出字符
int main()
{
    int ret = -1;
    pthread_t tid1 = -1, tid2 = -1;

    // 初始化信号量
    ret = sem_init(&sem, 0, 1);
    if (0 != ret)
    {
        printf("sem_init failed...\n");
        return 1;
    }
    printf("初始化一个信号量ok...\n");

    // 创建两个线程
    pthread_create(&tid1, NULL, fun1, NULL); 
    pthread_create(&tid2, NULL, fun2, NULL);

    // 等待两个线程结束
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    putchar('\n');
    printf("main thread exit...\n");

    // 销毁信号量
    sem_destroy(&sem);

    return 0;
}