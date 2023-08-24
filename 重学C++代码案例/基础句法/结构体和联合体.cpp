#include <iostream>
#include <string.h>
using namespace std;
#pragma pack(1)   // 改变编译器的内存对齐方式；pack(n) 修改参数，编译器将按照 n 个字节对齐

int main()
{
    union Score   //共用同一块内存空间，空间只取最大的那个
    {
        double fs;
        char level;
    };
    struct Student  // 结构体存在内存布局，结构体的大小为最大对齐数的整数倍
    {
        char name[6];
        int age;
        Score s;
    };

    //cout << sizeof(Score) << endl;   //8

    Student s1;
    strcpy_s(s1.name, "lili");
    s1.age = 16;
    s1.s.fs = 95.5;
    s1.s.level = 'A';

    cout << sizeof(Student) << endl;  //24

    //内存对齐是指将数据存放到一个是字的整数倍的地址指向的内存之中
    //所以实际操作时，尽量将小空间数据扎堆放置前面以节省空间

    system("pause");
    return 0;
}