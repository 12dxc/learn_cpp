#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// 线程处理函数
void *fun(void *arg)
{
    for (int i = 0; i != 3; ++i)
    {
        printf("pthread do working.. %d\n", i);
        sleep(1);
    }

    return (void *)0x3;
}

// 回收线程的资源
int main()
{
    pthread_t tid = -1;
    int ret = -1;
    void *retp = NULL;

    // 创建一个线程
    ret = pthread_create(&tid, NULL, fun, NULL);
    if (0 != ret)
    {
        printf("pthread_create failed...\n");
        return 1;
    }

    // 等待线程结束再回收资源  会阻塞
    ret = pthread_join(tid, &retp); // 参数2 存储线程退出状态
    if (0 != ret)
    {
        printf("pthread_join failed...\n");
        return 1;
    }
    printf("retp: %p\n", retp);
    printf("main thread exit...\n");

    return 0;
}