#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int flag = 0;
pthread_mutex_t mutex; // 互斥量
pthread_cond_t cond;   // 条件变量

// 改变条件的线程
void *fun1(void *arg)
{
    while (1)
    {
        // 加锁
        pthread_mutex_lock(&mutex);
        flag = 1;
        // 解锁
        pthread_mutex_unlock(&mutex);

        // 唤醒因为条件而阻塞的线程
        pthread_cond_signal(&cond);

        sleep(2);
    }

    return NULL;
}
// 等待条件的线程
void *fun2(void *arg)
{
    while (1)
    {
        // 加锁
        pthread_mutex_lock(&mutex);

        // 表示条件不满足
        if (0 == flag)
        {
            // 等待条件满足 会阻塞
            pthread_cond_wait(&cond, &mutex);
        }

        printf("线程2因为条件满足 开始运行...\n");
        flag = 0;

        // 解锁
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}
// 条件变量的应用
int main()
{
    int ret = -1;
    pthread_t tid1, tid2;

    // 初始化条件变量
    ret = pthread_cond_init(&cond, NULL);
    if (0 != ret)
    {
        printf("pthread_cond_init failed...\n");
        return 1;
    }
    // 初始化互斥量
    ret = pthread_mutex_init(&mutex, NULL);
    if (0 != ret)
    {
        printf("pthread_mutex_init failed...\n");
        return 1;
    }

    //  创建两个线程
    pthread_create(&tid1, NULL, fun1, NULL);
    pthread_create(&tid2, NULL, fun2, NULL);

    // 回收线程资源
    ret = pthread_join(tid1, NULL);
    if (0 != ret)
    {
        printf("pthread_join failed...\n");
        return 1;
    }
    ret = pthread_join(tid2, NULL);
    if (0 != ret)
    {
        printf("pthread_join failed...\n");
        return 1;
    }

    // 销毁条件变量
    pthread_cond_destroy(&cond);
    // 销毁互斥量
    pthread_mutex_destroy(&mutex);

    return 0;
}