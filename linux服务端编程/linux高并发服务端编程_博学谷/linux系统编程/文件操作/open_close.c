#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// 打开和关闭文件
int main()
{
    int fd = -1;

    // 1、以只读方式打开一个文件；如果文件不存在就报错
    // fd = open("txt", O_RDONLY);

    // 2、以只写的方式打开一个文件；如果文件存在就直接打开，如果文件不存在就新建一个文件
    // fd = open("txt", O_WRONLY | O_CREAT, 0644);

    // 3、以只写的方式打开一个文件夹；如果文件存在就报错，如果文件不存在就新建一个文件
    // fd = open("txt", O_WRONLY | O_EXCL, 0644);

    // 4、以读写的方式打开一个文件，如果文件存在就打开，如果文件不存在就新建一个文件
    // fd = open("txt", O_RDWR | O_CREAT, 0644);

    // 5、O_TRUNC 清空文件内容
    // fd = open("txt", O_WRONLY | O_TRUNC | O_CREAT, 0644);

    // 6、O_APPEND 追加的方式
    // 以只写的方式和追加的方式打开一个文件，如果文件不存在会报错
    fd = open("txt", O_WRONLY | O_APPEND);

    if (-1 == fd)
    {
        perror("open");
        return 1;
    }
    printf("文件描述符: %d\n", fd);

    // 关闭文件
    close(fd);

    return 0;
}