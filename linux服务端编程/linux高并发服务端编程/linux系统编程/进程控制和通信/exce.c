#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    char *args[] = {"ls", "-l", "/home", NULL};
    printf("hello world\n");

    // 参数为arg0,arg1,arg2...argn
    // arg0是可执行文件名，argn必须是NULL
    // execlp("ls", "ls", "-l", "/home", NULL); // 等价于ls -l /home

    // 与execlp一样，但传参可传一字符数组
    // execvp("ls", args);

    // 与execvp，但参1可执行文件 必须填路径
    execv("/bin/ls", args);

    // 跳至其他进程执行，故下条不会执行
    printf("hello world 2\n");

    return 0;
}
