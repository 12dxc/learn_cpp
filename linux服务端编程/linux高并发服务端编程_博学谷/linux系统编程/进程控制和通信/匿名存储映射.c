#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <linux/mman.h>
#include <wait.h>

// 父子进程使用匿名映射进行进程间通信
int main(void)
{
    int ret = -1;
    pid_t pid = -1;
    void *addr = NULL;

    // 1、创建匿名映射
    addr = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (MAP_FAILED == addr)
    {
        perror("mmap");
        return 1;
    }
    // 2、创建子进程
    pid = fork();
    if (-1 == pid)
    {
        perror("fork");
        munmap(addr, 4096);
        return 1;
    }

    // 3、父子进程通信
    if (0 == pid)
    {
        // 子进程写
        memcpy(addr, "1234567890", 10);
    }
    else
    {
        // 父进程读
        wait(NULL);
        printf("父进程读到了: %s\n", (char *)addr);
    }

    // 4、断开映射
    munmap(addr, 4096);

    return 0;
}