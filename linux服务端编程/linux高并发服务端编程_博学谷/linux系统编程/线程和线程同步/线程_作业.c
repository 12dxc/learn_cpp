#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *fun1(void *arg)
{
    for (int i = 'A'; i <= 'Z'; ++i)
    {
        putchar(i);
        usleep(100000); // 100ms
    }
}
void *fun2(void *arg)
{
    for (int i = 'a'; i <= 'z'; ++i)
    {
        putchar(i);
        usleep(100000);
    }
}
int main()
{
    pthread_t tid1 = -1, tid2 = -1;

    // 创建两个线程
    pthread_create(&tid1, NULL, fun1, NULL);
    pthread_create(&tid2, NULL, fun2, NULL);

    // 等待两个线程结束
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    putchar('\n');
    printf("main thread exit...\n");

    return 0;
}