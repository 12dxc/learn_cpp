#include <iostream>
#include <vector>
using namespace std;

using int_array = int[4];

int main()
{
    int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11},
    };

    // 输出ia的元素
    // 范围for循环
    for (int_array &row : ia)
    {
        for (int col : row)
        {
            cout << col << " ";
        }
    }
    cout << endl;

    // for循环 下标
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << ia[i][j] << " ";
        }
    }
    cout << endl;

    // for循环 指针
    for (int_array *p = ia; p != ia + 3; p++)
    {
        for (int *q = *p; q != *p + 4; q++)
        {
            cout << *q << " ";
        }
    }
    cout << endl;

    return 0;
}
