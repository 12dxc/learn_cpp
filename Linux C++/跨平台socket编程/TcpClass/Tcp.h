/* 封装了tcpServer和tcpClient */

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
#include <fcntl.h>
#define closesocket close
#endif

// 封装的跨平台socket的tcp连接类
class Tcp
{
public:
    Tcp()
    {
#ifdef WIN32
        static bool first = true;
        if (first)
        {
            first = false;
            WSADATA ws;
            WSAStartup(MAKEWORD(2, 2), &ws);
        }
#endif
    }

    virtual ~Tcp() = default;

    int createSocket()
    {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1)
            printf("create socket failed!\n");
        return sock;
    }

    bool bind(unsigned short port)
    {
        if (sock <= 0)
            createSocket();

        sockaddr_in saddr;
        saddr.sin_family = AF_INET;
        saddr.sin_port = htons(port);
        saddr.sin_addr.s_addr = 0; // 接收任何ip的连接

        if (::bind(sock, (struct sockaddr *)&saddr, sizeof(saddr)) != 0)
        {
            printf("bind port %d failed!\n", port);
            return false;
        }
        printf("bind port %d success!\n", port);
        listen(sock, 10);
        return true;
    }

    Tcp accept()
    {
        Tcp tcp;
        sockaddr_in caddr;
        socklen_t len = sizeof(caddr);
        int client = ::accept(sock, (struct sockaddr *)&caddr, &len);
        if (client <= 0)
        {
            printf("accept failed"); // 打印错误信息
            return tcp;
        }
        printf("accept client %d\n", client);
        tcp.ip = inet_ntoa(caddr.sin_addr);
        tcp.port = ntohs(caddr.sin_port);
        tcp.sock = client;
        printf("client ip is %s, port is %d\n", tcp.ip.c_str(), tcp.port);
        return tcp;
    }

    void close()
    {
        if (sock <= 0)
            return;
        ::closesocket(sock);
    }

    int recv(char *buf, int bufsize)
    {
        return ::recv(sock, buf, bufsize, 0);
    }

    int send(const char *buf, int size)
    {
        int s = 0;
        while (s != size)
        {
            int len = ::send(sock, buf + s, size - s, 0);
            if (len <= 0)
                break;
            s += len;
        }
        return s;
    }

    bool connect(const char *ip, unsigned short port, int timeout = 1000)
    {
        if (sock <= 0)
            createSocket();
        sockaddr_in saddr;
        saddr.sin_family = AF_INET;
        saddr.sin_port = htons(port);
        saddr.sin_addr.s_addr = inet_addr(ip);
        setBlock(false);
        fd_set set; // 文件句柄数组

        if (::connect(sock, (sockaddr *)&saddr, sizeof(saddr)) != 0)
        {
            // select实现非阻塞超时处理
            FD_ZERO(&set);
            FD_SET(sock, &set);
            timeval tm;
            tm.tv_sec = 0;
            tm.tv_usec = timeout * 1000;
            if (select(sock + 1, 0, &set, 0, &tm) <= 0)
            {
                printf("connect timeout or error!\n");
                printf("connect %s:%d failed!: %s\n", ip, port, strerror(errno));
                return false;
            }
        }
        setBlock(true);
        printf("connect %s:%d success!\n", ip, port);
        return true;
    }

    bool setBlock(bool isblock)
    {
        if (sock <= 0)
            return false;
#ifdef WIN32
        unsigned long ul = 0;
        if (!isblock)
            ul = 1;
        ioctlsocket(sock, FIONBIO, &ul);
#else
        int flags = fcntl(sock, F_GETFL, 0);
        if (flags < 0)
            return false;
        if (isblock)
        {
            flags = flags & ~O_NONBLOCK; // 与非
        }
        else
            flags = flags | O_NONBLOCK;
        if (fcntl(sock, F_SETFL, flags) != 0)
            return false;
#endif

        return true;
    }

    int sock = 0;
    unsigned short port = 0;
    string ip;
};
