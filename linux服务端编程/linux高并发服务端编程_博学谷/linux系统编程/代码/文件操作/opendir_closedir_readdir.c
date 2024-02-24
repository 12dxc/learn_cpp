#include <stdio.h>
#include <sys/fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>

// 目录的打开和关闭
int main()
{
    DIR *dir = NULL;
    struct dirent *d = NULL; // 保存目录结构体
    // 1、打开目录
    dir = opendir("txt"); // opendir() 返回指向该目录结构体指针
    if (NULL == dir)
    {
        perror("opendir");
        return 1;
    }
    printf("打开目录成功\n");

    // 2、循环读取目录内容
    while (1)
    {
        // 读取目录内容
        d = readdir(dir); // readdir() 目录结构体指针
        if (NULL == d)
        {
            break;
        }

        printf("d_type: %hu  d_name: %s\n", d->d_type, d->d_name);
    }

    // 3、关闭目录
    closedir(dir);

    return 0;
}