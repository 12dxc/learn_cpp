#include <stdio.h>
#include "wrap.h"
#include <event.h>

void *lfdcb(int lfd, short event, void *arg);
void *cfdcb(int cfd, short event, void *arg);

int main()
{
    // 创建套接字  绑定
    int lfd = tcp4bind(AF_INET, NULL);
    // 监听
    Listen(lfd, 128);
    // 创建event_base根节点
    struct event_base *base = event_base_new();
    // 初始化lfd上树节点
    struct event *ev = event_new(base, lfd, EV_READ | EV_PERSIST, lfdcb, base);
    // 上树
    event_add(ev, NULL); // 参2为空，表示永久监听
    // 循环监听
    event_base_dispatch(base);
    // 收尾
    close(lfd);
    event_base_free(base);

    return 0;
}

// 服务器事件
void *lfdcb(int lfd, short event, void *arg)
{
    struct event_base *base = (struct event_base *)arg;
    // 提取新的cfd
    int cfd = Accept(lfd, NULL, NULL);
    // 将cfd上树
    struct event *ev = event_new(base, cfd, EV_READ | EV_PERSIST, cfdcb, NULL);
    event_add(ev, NULL);
}
// 客户端事件
void *cfdcb(int cfd, short event, void *arg)
{
    char buf[1500] = "";
    int n = Read(cfd, buf, sizeof(buf));
    if (n <= 0)
    {
        perror("err or close..\n");
        // 下树
    }
    else
    {
        printf("%s\n", buf);
        Write(cfd, buf, n);
    }
}