#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// 线程处理函数
void *fun(void *arg)
{
    for (int i = 0; i != 5; ++i)
    {
        printf("pthread do working.. %d\n", i);
        sleep(1);
    }

    return NULL;
}

// 回收线程的资源
int main()
{
    pthread_t tid = -1;
    int ret = -1;

    // 创建一个线程
    ret = pthread_create(&tid, NULL, fun, NULL);
    if (0 != ret)
    {
        printf("pthread_create failed...\n");
        return 1;
    }

    // 设置线程分离  资源回收交由系统托管
    ret = pthread_detach(tid);
    if (0 != ret)
    {
        printf("pthread_detach failed...\n");
        return 1;
    }

    printf("按任意键退出...\n");
    getchar();

    return 0;
}