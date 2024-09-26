#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define BUF_SIZE 100 // 读写缓冲区大小
#define MAX_CLNT 256 // 已连接客户端的最大数量

void *handle_clnt(void *arg);
void send_msg(char *msg, int len);
void error_handling(char *msg);

// 用于管理已连接客户端，访问这两个变量的代码将构成临界区
int clnt_cnt = 0;         // 表示当前连接数
int clnt_socks[MAX_CLNT]; // 存储连接的客户端文件描述符

pthread_mutex_t mutex; // 需一把互斥锁

int main(int argc, char *argv[])
{
    int serv_sock, clnt_sock;
    struct sockaddr_in serv_adr, clnt_adr;
    int clnt_adr_sz; // 客户端ip结构体长度
    pthread_t tid;

    pthread_mutex_init(&mutex, NULL); // 初始化互斥量

    serv_sock = socket(AF_INET, SOCK_STREAM, 0);
    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_port = htons(8080);
    serv_adr.sin_addr.s_addr = htonl(INADDR_ANY); // 绑定本机下所有IP
    if (bind(serv_sock, (struct sockaddr *)&serv_adr, sizeof(serv_adr)) == -1)
        error_handling("binf() error");
    if (listen(serv_sock, 5) == -1)
        error_handling("listen() error");

    // 循环提取连接
    while (1)
    {
        clnt_adr_sz = sizeof(clnt_adr);
        clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_adr, &clnt_adr_sz);

        pthread_mutex_lock(&mutex);
        clnt_socks[clnt_cnt++] = clnt_sock; // 将提取的客户端套接字加入已连接客户端组
        pthread_mutex_unlock(&mutex);

        // 以多线程的方式响应客户端
        pthread_create(&tid, NULL, &handle_clnt, (void *)&clnt_sock);
        pthread_detach(tid); // 分离线程，由操作系统接管
        printf("Connected client IP: %s \n", inet_ntoa(clnt_adr.sin_addr));
    }
    close(serv_sock); // 关闭服务端套接字

    return 0;
}
// 处理客户端连接
void *handle_clnt(void *arg)
{
    int clnt_sock = *((int *)arg);
    int str_len = 0;
    char msg[BUF_SIZE]; // 缓冲区

    while ((str_len = read(clnt_sock, msg, sizeof(msg))) != 0)
        send_msg(msg, str_len);

    pthread_mutex_lock(&mutex);
    // 将此客户端套接字从已连接客户端组删除
    for (int i = 0; i != clnt_cnt; ++i)
    {
        if (clnt_sock == clnt_socks[i])
        {
            // 数组删除 后面数据前移
            while (++i < clnt_cnt - 1)
                clnt_socks[i] = clnt_socks[i + 1];
            break;
        }
    }
    --clnt_cnt;
    pthread_mutex_unlock(&mutex);
    close(clnt_sock);
    return NULL;
}
// 给全部已连接的客户端发送消息
void send_msg(char *msg, int len)
{
    pthread_mutex_lock(&mutex);
    for (int i = 0; i != clnt_cnt; ++i)
        write(clnt_socks[i], msg, len);
    pthread_mutex_unlock(&mutex);
}
// 错误处理
void error_handling(char *msg)
{
    fputs(msg, stderr);
    fputc('\n', stderr);
    exit(1);
}