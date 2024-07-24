#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <bits/sockaddr.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    // 1、创建套接字 socket
    int lfd = socket(AF_INET, SOCK_STREAM, 0);

    // 2、绑定 bind
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY; // INADDR_ANY 0 绑定通配地址，即本机所有ip
    int ret = bind(lfd, (struct sockaddr *)&addr, sizeof(addr));
    if (ret < 0)
    {
        perror("");
        exit(0);
    }

    // 3、监听 listen
    listen(lfd, 128); // 参数2，即未完成和已完成连接队列之和

    // 4、提取 accept
    struct sockaddr_in cliaddr; // 客户端信息
    socklen_t len = sizeof(cliaddr);
    int cfd = accept(lfd, (struct sockaddr *)&cliaddr, &len);
    // 打印客户端信息
    char ip[16] = "";
    printf("new client ip=%s port=%d\n", inet_ntop(AF_INET, &cliaddr.sin_addr.s_addr, ip, 16), ntohs(cliaddr.sin_port));

    // 5、读写
    char buf[128] = "";
    while (1)
    {
        bzero(buf, sizeof(buf));     // 清空
        read(cfd, buf, sizeof(buf)); // 读客户端发送的信息
        printf("%s\n", buf);
    }

    // 6、关闭
    close(lfd);
    close(cfd);

    return 0;
}