#include <stdio.h>
#include <arpa/inet.h>
#include <bits/sockaddr.h>
#include <sys/socket.h>
#include <unistd.h>

// 客户端通信
int main()
{
    // 1、创建套接字
    int sock_fd = -1;
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    // 2、连接服务器
    // socket地址结构体
    struct sockaddr_in addr;                                     // 专用套接字，用于ipv4
    addr.sin_family = AF_INET;                                   // 协议类型（地址簇），赋值为ipv4
    addr.sin_port = htons(8080);                                 // 端口，网络上需转成大端
    inet_pton(AF_INET, "192.168.10.107", &addr.sin_addr.s_addr); // Ipv4地址，要转为字节序
    // 发起连接
    connect(sock_fd, (struct sockaddr *)&addr, sizeof(addr)); // 参数2 专用socket地址需转为通用

    // 3、读写数据
    char buf[1024] = "";
    while (1)
    {
        // STDIN_FILENO  标准输入
        int n = read(STDIN_FILENO, buf, sizeof(buf));
        write(sock_fd, buf, sizeof(buf)); // 发送数据给服务器
        // 等待服务器回应，才可继续输入
        n = read(sock_fd, buf, sizeof(buf));
        // STDOUT_FILENO  标准输出
        write(STDOUT_FILENO, buf, n);
    }

    // 4、关闭
    close(sock_fd);

    return 0;
}