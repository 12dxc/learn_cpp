#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

int main()
{
    // 绑定指定文件时，此文件必须不存在，否则绑定失败，故先作删除
    unlink("sock.s");
    // 1、创建unix流式套接字
    int lfd = socket(AF_UNIX, SOCK_STREAM, 0);
    // 2、绑定
    struct sockaddr_un myaddr;
    myaddr.sun_family = AF_UNIX;
    strcpy(myaddr.sun_path, "sock.s");
    // offsetof() 计算结构体成员的偏移量
    int len = offsetof(struct sockaddr_un, sun_path) + strlen(myaddr.sun_path);
    bind(lfd, (struct sockaddr *)&myaddr, sizeof(myaddr));
    // 3、监听
    listen(lfd, 128);
    // 4、提取
    struct sockaddr_un cliaddr;
    len = sizeof(cliaddr);
    int cfd = accept(lfd, (struct sockaddr *)&cliaddr, &len);

    printf("new client file = %s\n", cliaddr.sun_path);
    // 5、读写
    char buf[1500] = "";
    while (1)
    {
        int n = recv(cfd, buf, sizeof(buf), 0);
        if (n <= 0)
        {
            printf("err or client close\n");
            break;
        }
        else
        {
            printf("%s", buf);
            send(cfd, buf, n, 0);
        }
    }

    // 6、关闭
    close(cfd);
    close(lfd);

    return 0;
}