#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void)
{
    int ret = -1;
    struct stat s;

    // 获取指定文件的信息
    ret = stat("txt", &s);
    if (-1 == ret)
    {
        perror("stat");
        return 1;
    }

    // 文件属性信息
    printf("st_dev: %lu\n", s.st_dev);     // 设备编号
    printf("st_ino: %ld\n", s.st_ino);     // 节点
    printf("st_nlink: %lu\n", s.st_nlink); // 硬链接数
    printf("st_uid: %d\n", s.st_uid);      // 用户ID
    printf("st_gid: %d\n", s.st_gid);      // 组ID
    printf("st_size: %ld\n", s.st_size);   // 文件大小
}