/* 使用epoll的tcp服务器 */

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <thread>
using namespace std;

#include "Tcp.h"

class TcpThread
{
public:
    void Main()
    {
        char buf[1024] = {0};
        while (true)
        {

            int recvlen = client.recv(buf, sizeof(buf) - 1);
            if (recvlen < 0)
                break;
            buf[recvlen] = '\0';
            if (strstr(buf, "quit") != nullptr)
            {
                char re[] = "quit success!\n";
                client.send(re, strlen(re) + 1);
                break;
            }
            int sendlen = client.send("ok\n", 4);

            printf("recv %s\n", buf);
        }
        client.close();
        delete this;
    }
    Tcp client;
};
#include <sys/epoll.h>
int main(int argc, char *argv[])
{
    unsigned short port = 8080;
    if (argc > 1)
        port = atoi(argv[1]);

    Tcp server;
    server.createSocket();
    server.bind(port);

    // 使用epoll创建高并发服务器
    // 1、创建epoll
    int epfd = epoll_create(256);
    // 2、注册事件
    epoll_event ev;
    ev.data.fd = server.sock;
    ev.events = EPOLLIN | EPOLLET;
    epoll_ctl(epfd, EPOLL_CTL_ADD, server.sock, &ev);
    epoll_event events[20]; // 等待的事件

    char buf[1024] = {0};
    const char *msg = "HTTP/1.1 200 OK \r\nContent-Length: 1\r\n\r\nX";
    int size = strlen(msg);
    server.setBlock(false);
    while (true)
    {
        int count = epoll_wait(epfd, events, 20, 500);
        if (count <= 0)
            continue;
        for (int i = 0; i < count; i++)
        {
            if (events[i].data.fd == server.sock)
            {
                while (true)
                {
                    Tcp client = server.accept();
                    if (client.sock <= 0)
                        break;
                    ev.data.fd = client.sock;
                    ev.events = EPOLLIN | EPOLLET;
                    epoll_ctl(epfd, EPOLL_CTL_ADD, client.sock, &ev);
                }
            }
            else
            {
                Tcp client;
                client.sock = events[i].data.fd;
                client.recv(buf, 1024);
                client.send(msg, size);
                epoll_ctl(epfd, EPOLL_CTL_DEL, client.sock, &ev);
            }
        }

        // Tcp client = server.accept();
        // TcpThread *th = new TcpThread();
        // th->client = client;
        // thread sth(&TcpThread::Main, th);
        // sth.detach();
    }
    server.close();

    getchar();
    return 0;
}
