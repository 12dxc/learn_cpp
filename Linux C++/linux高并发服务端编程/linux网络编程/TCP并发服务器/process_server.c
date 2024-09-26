#include <stdio.h>
#include <signal.h>
#include <wait.h>
#include "wrap.h"

void free_process(int sig)
{
    pid_t pid;
    while (1)
    {
        pid = waitpid(-1, NULL, WNOHANG); // WNOHANG 不挂起直接返回
        if (pid <= 0)                     // <0 子进程全部退出了，=0 没有进程退出
        {
            break;
        }
        else
        {
            printf("child pid=%d\n", pid);
        }
    }
}
int main()
{
    // 为防止注册信号前，进程就退出了，先屏蔽此信号
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set, SIGCHLD);

    // 创建套接字，绑定
    int lfd = tcp4bind(8080, NULL); // NULL表示所有的

    // 监听
    Listen(lfd, 128);

    struct sockaddr_in cliaddr;
    socklen_t len = sizeof(cliaddr);
    while (1)
    {
        // 提取连接
        char ip[16] = "";
        int cfd = Accept(lfd, (struct sockaddr *)&cliaddr, &len);
        printf("new client ip=%s, port=%d\n", inet_ntop(AF_INET, &cliaddr.sin_addr.s_addr, ip, 16),
               cliaddr.sin_port);

        // 创建子进程
        pid_t pid;
        pid = fork();
        if (pid < 0)
        {
            perror("fork");
            exit(0);
        }
        else if (pid == 0) // 子进程
        {
            // 关闭lfd
            close(lfd);
            // 再加一层循环，无法读取时直接退出进程，防止关闭服务器套接字之后，再次提取
            while (1)
            {
                // 回声（回射）实现
                char buf[1024] = "";
                int n = read(cfd, buf, sizeof(buf));
                if (n < 0) // read  返回-1，读取出错
                {
                    perror("");
                    close(cfd);
                    exit(0);
                }
                else if (n == 0) // read  返回0，说明对方已关闭
                {
                    printf("client close\n");
                    close(cfd);
                    exit(0);
                }
                else // read  返回值 > 0，则读取成功，响应客户端
                {
                    printf("%s\n", buf);
                    write(cfd, buf, n);
                }
            }
        }
        else // 父进程
        {
            close(cfd);
            // 回收
            // 注册信号回调
            struct sigaction act;
            act.sa_flags = 0;
            act.sa_handler = free_process;
            sigemptyset(&act.sa_mask);
            sigaction(SIGCHLD, &act, NULL);
            sigprocmask(SIG_UNBLOCK, &set, NULL);
        }
    }

    // 关闭
    return 0;
}