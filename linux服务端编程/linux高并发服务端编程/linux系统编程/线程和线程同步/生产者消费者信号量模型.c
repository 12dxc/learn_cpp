#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

// 链表节点
typedef struct _node_t
{
    int data;
    struct _node_t *next;
} node_t;

node_t *head = NULL; // 链表头

// 信号量变量
sem_t sem_producer; // 商品货架空置大小
sem_t sem_customer; // 可以卖的产品个数

// 生产者线程
void *producer(void *arg)
{
    // 循环生产商品
    while (1)
    {
        // 申请资源 占用一格货架
        sem_wait(&sem_producer);

        node_t *new = malloc(sizeof(node_t)); // 新建节点
        if (NULL == new)
        {
            printf("malloc failed...\n");
            break;
        }
        memset(new, 0, sizeof(node_t)); // 情况分配的内存

        // 初始化新建节点
        new->data = random() % 100 + 1; // 1-100
        new->next = NULL;
        printf("生产者生产产品 %d\n", new->data);

        // 连接节点   头插法
        new->next = head;
        head = new;

        // 通知消费者消费，将可以买的商品个数加1
        sem_post(&sem_customer);

        // 随机睡眠 1-3秒
        sleep(random() % 3 + 1);
    }

    pthread_exit(NULL);
}
// 消费者线程
void *customer(void *arg)
{
    node_t *tmp = NULL; // 取走商品
    // 循环消费
    while (1)
    {
        // 申请资源 等待商品生产并买走，即减1
        sem_wait(&sem_customer);

        // 删除节点 头删法
        tmp = head;
        head = head->next;

        printf("消费者消费 %d\n", tmp->data);
        free(tmp);

        // 释放资源 货架空1格，即加1
        sem_post(&sem_producer);

        // 随机睡眠 1-3秒
        sleep(random() % 3 + 1);
    }

    pthread_exit(NULL);
}
// 条件变量的应用
int main()
{
    int ret = -1;
    pthread_t tid[6];

    // 初始化信号量
    ret = sem_init(&sem_producer, 0, 4);
    if (0 != ret)
    {
        printf("sem_init failed...\n");
        return 1;
    }
    ret = sem_init(&sem_customer, 0, 0);
    if (0 != ret)
    {
        printf("sem_init failed...\n");
        return 1;
    }

    //  创建6个线程 分别是2个生产者线程和4个消费者线程
    for (int i = 0; i != 6; ++i)
    {
        if (i != 2)
        { // 生产者
            pthread_create(&tid[i], NULL, producer, NULL);
        }
        else
        { // 消费者
            pthread_create(&tid[i], NULL, customer, NULL);
        }
    }

    // 回收线程资源
    for (int i = 0; i != 6; ++i)
        pthread_join(tid[i], NULL);

    // 销毁
    sem_destroy(&sem_producer);
    sem_destroy(&sem_customer);

    return 0;
}
