#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <process.h>
#pragma comment(lib, "ws2_32.lib")

#define BUF_SIZE 100 // 读写缓冲区大小
#define NAME_SIZE 20

unsigned WINAPI send_msg(void *arg);
unsigned WINAPI recv_msg(void *arg);
void error_handling(char *msg);

char name[NAME_SIZE] = "[default]"; // 本机用户名
char msg[BUF_SIZE];                 // 读写缓冲区

int main(int argc, char *argv[])
{
    printf("Input your Chat Name:\n");
    scanf("%s", name);
    SOCKET sock;
    SOCKADDR_IN serv_adr;
    HANDLE send_thread, recv_thread;

    // 初始化windows套接字
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
        error_handling("WSAStartup() error");
    sock = socket(AF_INET, SOCK_STREAM, 0);

    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_port = htons(8080);
    serv_adr.sin_addr.s_addr = inet_addr("118.126.111.181");

    if (connect(sock, (struct sockaddr *)&serv_adr, sizeof(serv_adr)) == -1)
        error_handling("connect() error");

    // 分别创建两个线程发送数据和接收数据
    send_thread = (HANDLE)_beginthreadex(NULL, 0, send_msg, (void *)&sock, 0, NULL);
    recv_thread = (HANDLE)_beginthreadex(NULL, 0, recv_msg, (void *)&sock, 0, NULL);

    WaitForSingleObject(send_thread, INFINITE);
    WaitForSingleObject(recv_thread, INFINITE);

    closesocket(sock);
    WSACleanup();

    return 0;
}

// 发送主线程
unsigned WINAPI send_msg(void *arg)
{
    SOCKET sock = *((SOCKET *)arg);
    char name_msg[NAME_SIZE + BUF_SIZE];
    while (1)
    {
        fgets(msg, BUF_SIZE, stdin);
        if (!strcmp(msg, "q\n") || !strcmp(msg, "Q\n"))
        {
            closesocket(sock);
            exit(0);
        }
        sprintf(name_msg, "%s %s", name, msg);
        send(sock, name_msg, strlen(name_msg), 0);
    }
    return 0;
}
// 读主线程
unsigned WINAPI recv_msg(void *arg)
{
    SOCKET sock = *((SOCKET *)arg);
    char name_msg[NAME_SIZE + BUF_SIZE];
    int str_len;
    while (1)
    {
        str_len = recv(sock, name_msg, NAME_SIZE + BUF_SIZE - 1, 0);
        if (str_len == -1)
            return -1;
        name_msg[str_len] = 0;
        fputs(name_msg, stdout);
    }
    return 0;
}
// 错误处理
void error_handling(char *msg)
{
    fputs(msg, stderr);
    fputc('\n', stderr);
    exit(1);
}
