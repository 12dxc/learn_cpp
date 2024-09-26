#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

// ip地址转换函数
int main()
{
    char buf[] = "192.168.1.4";
    unsigned int num = 0;
    // 将字符串转成网络ip地址
    inet_pton(AF_INET, buf, &num);
    unsigned char *p = (unsigned char *)&num;

    printf("%d %d %d %d\n", *p, *(p + 1), *(p + 2), *(p + 3));

    char ip[16] = "";
    // 将网络ip地址转成字符串  多一个参数为字符串长度
    printf("%s\n", inet_ntop(AF_INET, &num, ip, 16));

    return 0;
}