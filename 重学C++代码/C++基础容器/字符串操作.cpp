#include <iostream>
using namespace std;
#include <cstring>

int main()
{
    char str[] = {"hello world"};
    for (int i = 0; i < strlen(str); i++)
    {
        cout << str[i];
    }
    cout << endl;

    cout << "字符串长度为：" << strlen(str) << endl; // 长度不包括 /0
    cout << "字符串占用的空间为：" << sizeof(str) << endl;

    // 字符串比较 strcmp(),依照ASCII码比较
    const char *a = "AB";
    const char *b = "CD";
    cout << "字符串 AB 与 CD 的结果：" << strcmp(b, a) << endl; //= 返回 0,> 返回 1,< 返回 -1

    // 字符串拷贝 strcpy(),依次将字符复制到一个新的字符串
    char *copyA;
    strcpy(copyA, a); // 参数1 拷贝到的新值,参数2 要拷贝的值
    cout << "copy a = " << copyA << endl;

    // 字符串拼接 strcat(),将参数1和参数2的值拼在一起
    char str1[] = {"hello "};
    char str2[] = {"world"};

    char *s1_And_s2 = strcat(str1, str2);
    cout << "s1 and s2 = " << s1_And_s2 << endl;

    // 字符串查找  strchr(s1,char),strstr(s1,string)

    // 尽量使用加 _s的函数，更加安全，会提示缓冲区能否容纳数据

    return 0;
}