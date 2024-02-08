#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// 互斥锁变量
pthread_mutex_t mutex1;
pthread_mutex_t mutex2;

// 线程1执行函数
void *fun1(void *arg)
{
    // 线程1先申请资源1 再申请资源2
    pthread_mutex_lock(&mutex1);
    printf("线程1加锁资源1 ok...\n");
    pthread_mutex_lock(&mutex2);
    printf("线程1加锁资源2 ok...\n");
    printf("线程1执行临界区代码");

    // 解锁
    pthread_mutex_unlock(&mutex1);
    pthread_mutex_unlock(&mutex2);
}
// 线程2执行函数
void *fun2(void *arg)
{
    // 线程1先申请资源2 再申请资源1
    pthread_mutex_lock(&mutex2);
    printf("线程2加锁资源2 ok...\n");
    pthread_mutex_lock(&mutex1);
    printf("线程2加锁资源1 ok...\n");

    printf("线程1执行临界区代码");

    // 解锁
    pthread_mutex_unlock(&mutex2);
    pthread_mutex_unlock(&mutex1);
}
// 模拟输出字符
int main()
{
    int ret = -1;
    pthread_t tid1 = -1, tid2 = -1;

    // 创建互斥锁/量
    pthread_mutex_init(&mutex1, NULL);
    pthread_mutex_init(&mutex2, NULL);

    // 创建两个线程
    pthread_create(&tid1, NULL, fun1, NULL);
    pthread_create(&tid2, NULL, fun2, NULL);

    // 等待两个线程结束
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    putchar('\n');
    printf("main thread exit...\n");

    // 销毁互斥锁/量
    pthread_mutex_destroy(&mutex1);
    pthread_mutex_destroy(&mutex2);

    return 0;
}