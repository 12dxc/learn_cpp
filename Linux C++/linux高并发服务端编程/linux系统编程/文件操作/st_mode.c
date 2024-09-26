#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

// 显示文件类型的第一个版本
int show_fileType(struct stat *s)
{
    // 使用文件类型宏
    switch (s->st_mode & __S_IFMT)
    {
    // 普通文件
    case __S_IFREG:
        printf("该文件是普通文件\n");
        break;
    // 目录
    case __S_IFDIR:
        printf("该文件是目录\n");
        break;
    // 字符设备
    case __S_IFCHR:
        printf("该文件是字符设备\n");
        break;
    // 块设备
    case __S_IFBLK:
        printf("该文件是块设备\n");
        break;
    // 套接字
    case __S_IFSOCK:
        printf("该文件是套接字\n");
        break;
    // 管道
    case __S_IFIFO:
        printf("该文件是管道\n");
        break;
    default:
        printf("未知文件\n");
        break;
    }
}

// 显示文件类型的第二个版本
int show_fileType2(struct stat *s)
{
    // 使用文件类型判断宏函数 参数为st_mode
    //  普通文件
    if (S_ISREG(s->st_mode))
        printf("该文件是普通文件\n");
    // 目录
    if (S_ISDIR(s->st_mode))
        printf("该文件是目录\n");
    // 字符设备
    if (S_ISCHR(s->st_mode))
        printf("该文件是字符设备\n");
    // 块设备
    if (S_ISBLK(s->st_mode))
        printf("该文件是块设备\n");
    // 套接字
    // if (S_ISSOCK(s->st_mode))
    //     printf("该文件是套接字\n");
    // 管道
    if (S_ISFIFO(s->st_mode))
        printf("该文件是管道\n");
}
// 显示文件所属者的权限
void show_permisson(struct stat *s)
{
    // 判断文件所属者读权限
    if (s->st_mode & S_IRUSR)
    {
        printf("r");
    }
    else
    {
        printf("-");
    }

    // 判断文件所属者写权限
    if (s->st_mode & S_IWUSR)
    {
        printf("w");
    }
    else
    {
        printf("-");
    }

    // 判断文件所属者执行权限
    if (s->st_mode & S_IXUSR)
    {
        printf("x");
    }
    else
    {
        printf("-");
    }

    // 判断文件所属组读权限
    if (s->st_mode & S_IRGRP)
    {
        printf("r");
    }
    else
    {
        printf("-");
    }

    // 判断文件所属组写权限
    if (s->st_mode & S_IWGRP)
    {
        printf("w");
    }
    else
    {
        printf("-");
    }

    // 判断文件所属组执行权限
    if (s->st_mode & S_IXGRP)
    {
        printf("x");
    }
    else
    {
        printf("-");
    }

    // 判断文件其他读权限
    if (s->st_mode & S_IROTH)
    {
        printf("r");
    }
    else
    {
        printf("-");
    }

    // 判断文件其他写权限
    if (s->st_mode & S_IWOTH)
    {
        printf("w");
    }
    else
    {
        printf("-");
    }

    // 判断文件其他执行权限
    if (s->st_mode & S_IXOTH)
    {
        printf("x");
    }
    else
    {
        printf("-");
    }
}
// 用以显示文件类型  使用方式 ./st_mode filePath
int main(int argc, char **argv)
{
    int ret = -1;
    struct stat s;

    // 获取指定文件的信息
    ret = stat(argv[1], &s);
    if (-1 == ret)
    {
        perror("stat");
        return 1;
    }

    // 显示文件的类型
    show_fileType(&s);
    show_fileType2(&s);

    // 显示文件的权限
    show_permisson(&s);
    putchar('\n');

    return 0;
}