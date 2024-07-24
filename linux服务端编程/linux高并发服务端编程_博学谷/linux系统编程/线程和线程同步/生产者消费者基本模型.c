#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

// 链表节点
typedef struct _node_t
{
    int data;
    struct _node_t *next;
} node_t;

node_t *head = NULL; // 链表头

// 生产者线程
void *producer(void *arg)
{
    // 循环生产商品
    while (1)
    {
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
        // 链表为空
        if (NULL == head)
        {
            printf("产品为空...先休息2秒...\n");
            sleep(2);
        }

        // 删除节点 头删法
        tmp = head;
        head = head->next;

        printf("消费者消费 %d\n", tmp->data);
        free(tmp);

        // 随机睡眠 1-3秒
        sleep(random() % 3 + 1);
    }

    pthread_exit(NULL);
}
// 条件变量的应用
int main()
{
    pthread_t tid1 = -1, tid2 = -1;

    //  创建两个线程 分别为生产者线程和消费者线程
    pthread_create(&tid1, NULL, producer, NULL);
    pthread_create(&tid2, NULL, customer, NULL);

    // 回收线程资源
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    return 0;
}
