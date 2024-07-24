#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int num = 100; // 全局变量
int *p = NULL;

// 区分父子进程
int main()
{
    int var = 88; // 局部变量
    pid_t pid = -1;
    // 在堆区创建变量
    p = malloc(sizeof(int));
    *p = 200;

    // 创建一个子进程
    pid = fork(); // fork函数在子进程中返回0  在父进程中返回子进程的pid
    if (pid < 0)
    {
        // 没有创建成功
        perror("fork");
        return 1;
    }

    // 父子进程各自的地址空间是独立的
    if (0 == pid)
    {
        // 子进程
        sleep(1);
        printf("子进程睡眠之后 num = %d  var = %d  *p = %d\n", num, var, *p); // 88 100
        // 堆在父子进程中申请一次，但需释放两次
        free(p);
    }
    else
    {
        // 父进程
        printf("父进程之前 num = %d  var = %d  *p = %d\n", num, var, *p); // 88 100
        ++var;
        ++num;
        ++*p;
        printf("父进程之前 num = %d  var = %d  *p = %d\n", num, var, *p); // 89 101
        free(p);
    }
}