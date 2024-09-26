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

int main(int argc, char *argv[])
{
    unsigned short port = 8080;
    if (argc > 1)
        port = atoi(argv[1]);

    Tcp server;
    server.createSocket();
    server.bind(port);
    while (true)
    {
        Tcp client = server.accept();

        TcpThread *th = new TcpThread();
        th->client = client;
        thread sth(&TcpThread::Main, th);
        sth.detach();
    }
    server.close();

    getchar();
    return 0;
}
