#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// 读写锁变量
pthread_rwlock_t rwlock;

// 全局变量
int num = 0;

// 读线程
void *fun_read(void *arg)
{
    // 获取线程的编号
    int index = (int)(long)arg;

    while (1)
    {
        // 加读锁
        pthread_rwlock_rdlock(&rwlock);

        printf("线程%d 读取num的值 %d\n", index, num);

        // 解锁
        pthread_rwlock_unlock(&rwlock);

        // 随机睡眠1-3秒
        sleep(random() % 3 + 1);
    }

    return NULL;
}
// 写线程
void *fun_write(void *arg)
{
    int index = (int)(long)arg;

    while (1)
    {
        // 加写锁
        pthread_rwlock_wrlock(&rwlock);

        ++num;
        printf("线程%d 修改num的值 %d\n", index, num);

        // 解锁
        pthread_rwlock_unlock(&rwlock);

        // 随机睡眠1-3秒
        sleep(random() % 3 + 1);
    }

    return NULL;
}
int main()
{
    int ret = -1;
    pthread_t tid[8];

    // 获取随机数种子
    srandom(getpid());

    // 初始化读写锁
    ret = pthread_rwlock_init(&rwlock, NULL);
    if (0 != ret)
    {
        printf("pthread_rwlock_init failed...\n");
        return 1;
    }

    // 创建8个线程
    for (int i = 0; i != 8; ++i)
    {
        // 创建读线程
        if (i != 5)
        {
            pthread_create(&tid[i], NULL, fun_read, (void *)(long)i);
        }
        else
        {
            // 创建写线程
            pthread_create(&tid[i], NULL, fun_write, (void *)(long)i);
        }
    }

    // 回收8个线程的资源
    for (int i = 0; i != 8; ++i)
    {
        pthread_join(tid[i], NULL);
    }

    // 销毁读写锁
    pthread_rwlock_destroy(&rwlock);

    return 0;
}