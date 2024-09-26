#include <iostream>
using namespace std;

#include "Tcp.h"

int main()
{
    Tcp client;
    client.createSocket();
    client.setBlock(false);
    client.connect("127.0.0.1", 8080);
    client.send("client", 6);
    char buf[1024] = {0};
    client.recv(buf, sizeof(buf));
    printf("%s\n", buf);

    getchar();
    return 0;
}
