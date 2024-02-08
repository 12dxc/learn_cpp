#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <wait.h>

// 存储映射
int main(void)
{
    int fd = -1;
    int ret = -1;
    pid_t pid = -1;
    void *addr = NULL;

    // 1、以读写的方式打开一个文件
    fd = open("txt", O_RDWR);
    if (-1 == fd)
    {
        perror("open");
        return 1;
    }

    // 2、将文件映射到内存
    addr = mmap(NULL, 1024, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED)
    {
        perror("mmap");
        return 1;
    }

    printf("文件存储映射ok...\n");

    // 3、关闭文件
    close(fd);

    // 4、读存储映射区
    printf("addr: %s\n", (char *)addr);

    // 5、断开存储映射
    munmap(addr, 1024);

    return 0;
}