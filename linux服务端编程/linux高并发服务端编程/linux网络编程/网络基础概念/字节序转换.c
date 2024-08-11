#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

// 网络字节序和主机字节序的转换
int main()
{
    // 主机转网络字节序
    unsigned char buf[4] = {192, 168, 1, 1};
    int num = *(int *)buf;
    int sum = htonl(num);
    unsigned char *p = (unsigned char *)&sum;

    printf("%d %d %d %d\n", *p, *(p + 1), *(p + 2), *(p + 3));

    unsigned short a = 0x0102;
    unsigned short b = htons(a);
    printf("%x\n", b);

    // 网络转主机字节序
    unsigned char buf2[4] = {1, 1, 168, 192};
    int num2 = *(int *)buf2;
    int sum2 = ntohl(num2);
    unsigned char *p2 = (unsigned char *)&sum;
    printf("%d %d %d %d\n", *p2, *(p2 + 1), *(p2 + 2), *(p2 + 3));

    return 0;
}