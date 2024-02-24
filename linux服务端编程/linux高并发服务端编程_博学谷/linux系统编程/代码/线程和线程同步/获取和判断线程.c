#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// 线程常用函数
int main()
{
    pthread_t tid = 0; // 线程号类型

    // 获取当前线程的线程号
    tid = pthread_self();
    printf("tid: %lu\n", tid);

    // 比较两个线程ID是否相等
    if (pthread_equal(tid, pthread_self()))
    {
        printf("两个线程ID相同...\n");
    }
    else
    {
        printf("两个线程ID不相同...\n");
    }

    return 0;
}