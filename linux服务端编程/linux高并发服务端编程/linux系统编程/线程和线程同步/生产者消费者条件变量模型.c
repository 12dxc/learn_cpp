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

pthread_cond_t cond;   // 条件变量
pthread_mutex_t mutex; // 互斥量

// 生产者线程
void *producer(void *arg)
{
    // 循环生产商品
    while (1)
    {
        // 加锁
        pthread_mutex_lock(&mutex);

        // 新建节点
        node_t *new = malloc(sizeof(node_t));
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

        // 解锁
        pthread_mutex_unlock(&mutex);

        // 唤醒因为条件而阻塞的线程
        pthread_cond_signal(&cond);

        // 随机睡眠 1-3秒
        sleep(random() % 3 + 1);
    }

    pthread_exit(NULL);
}
// 消费者线程
void *customer(void *arg)
{
    // 加锁
    pthread_mutex_lock(&mutex);

    node_t *tmp = NULL; // 取走商品
    // 循环消费
    while (1)
    {
        // 链表为空
        if (NULL == head)
        {
            // printf("产品为空...先休息2秒...\n");
            //  如果链表为空就阻塞
            pthread_cond_wait(&cond, &mutex);
        }

        // 删除节点 头删法
        tmp = head;
        head = head->next;

        printf("消费者消费 %d\n", tmp->data);
        free(tmp);

        // 解锁
        pthread_mutex_unlock(&mutex);

        // 随机睡眠 1-3秒
        sleep(random() % 3 + 1);
    }

    pthread_exit(NULL);
}
// 条件变量的应用
int main()
{
    int ret = -1;
    pthread_t tid1 = -1, tid2 = -1;

    srandom(getpid()); // 设置随机数种子

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

    //  创建两个线程 分别为生产者线程和消费者线程
    pthread_create(&tid1, NULL, producer, NULL);
    pthread_create(&tid2, NULL, customer, NULL);

    // 回收线程资源
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    // 销毁
    pthread_cond_destroy(&cond);
    pthread_mutex_destroy(&mutex);

    return 0;
}
