/* 跨平台socket库使用 */

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <thread>
using namespace std;

#ifdef WIN32
#include <windows.h>
#define socklen_t int
#else
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#define closesocket close
#endif

class TcpThread
{
public:
    void Main()
    {
        char buf[1024] = {0};
        while (true)
        {

            int recvlen = recv(client, buf, sizeof(buf) - 1, 0);
            if (recvlen < 0)
                break;
            buf[recvlen] = '\0';
            if (strstr(buf, "quit") != nullptr)
            {
                char re[] = "quit success!\n";
                send(client, re, strlen(re) + 1, 0);
                break;
            }
            int sendlen = send(client, "ok\n", 4, 0);

            printf("recv %s\n", buf);
        }
        closesocket(client);
        delete this;
    }
    int client = 0;
};

int main(int argc, char *argv[])
{
#ifdef WIN32
    WSADATA ws;
    WSAStartup(MAKEWORD(2, 2), &ws);
#endif
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        printf("create socket failed!\n");
        return -1;
    }

    unsigned short port = 8080;
    if (argc > 1)
        port = atoi(argv[1]);

    sockaddr_in saddr;
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(port);
    saddr.sin_addr.s_addr = 0; // 接收任何ip的连接

    if (::bind(sock, (sockaddr *)&saddr, sizeof(saddr)) != 0)
    {
        printf("bind port %d failed!\n", port);
        return -2;
    }
    printf("bind port %d success!\n", port);
    listen(sock, 10);

    // 连接客户端
    while (true)
    {
        sockaddr_in caddr;
        socklen_t len = 0;
        int client = accept(sock, (sockaddr *)&caddr, &len);
        if (client <= 0)
            break;
        printf("accept client %d\n", client);
        char *ip = inet_ntoa(caddr.sin_addr);
        unsigned short cport = ntohs(caddr.sin_port);
        printf("client ip is %s, port is %d\n", ip, cport);
        TcpThread *th = new TcpThread();
        th->client = client;
        thread sth(&TcpThread::Main, th);
        sth.detach();
    }

    closesocket(sock);

    getchar();
    return 0;
}
