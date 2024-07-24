#include <iostream>
using namespace std;

int main()
{
    // 数组指针，元素都是指针的数组
    int *a[4];
    // 指针数组，一个指向数组的指针
    int(*b)[4];

    int c[4] = {0x800000, 0xFFFFFF, 0x000000, 0x7FFFFF};
    b = &c; // 指针数组可直接赋值
    for (unsigned int i = 0; i < 4; i++)
    {
        a[i] = &(c[i]); // 数组指针需遍历每一个元素进行赋值
    }

    for (int i = 0; i < 4; i++)
    {
        cout << *(a[i]) << endl;
        cout << (*b)[i] << endl;
    }

    return 0;
}