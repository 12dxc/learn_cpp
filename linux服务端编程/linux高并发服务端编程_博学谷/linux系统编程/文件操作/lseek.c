#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

// lseek使用
int main()
{
	int fd = -1;
	int ret = -1;
	char buf[128];

	// 1、打开文件
	fd = open("txt", O_RDWR | O_CREAT, 0644);
	if (-1 == fd)
	{
		perror("open");
		return 1;
	}
	printf("fd = %d\n", fd);

	// 2、lseek操作
	write(fd, "ABCDEF", 7);

	// 从文件开头偏移32个字节
	ret = lseek(fd, 32, SEEK_SET);
	if (-1 == ret)
	{
		perror("lseek");
		return 1;
	}
	write(fd, "1234567890", 10);

	// 将文件位置指针指向文件开头
	lseek(fd, 0, SEEK_SET);
	memset(buf, 0, 128); // 数组清零
	read(fd, buf, 128);
	printf("read buf: %s\n", buf);

	// 3、关闭文件
	close(fd);

	return 0;
}
