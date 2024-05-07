#include <cstdlib>
using namespace std;
#include <signal.h>
#include "http.h"

int main(int argc, char *argv[])
{
    signal(SIGPIPE, SIG_IGN); // 忽略信号
    unsigned short port = 8080;
    if (argc > 1)
        port = atoi(argv[1]);

    HttpServer server;
    server.start(port);

    getchar();
    return 0;
}
