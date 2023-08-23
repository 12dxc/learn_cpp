#include <iostream>
using namespace std;

int main()
{
    // 例1:
    int i = 2147483640;
    for (; i > 0; i++)
    {
        cout << "adding:" << i << endl; // int类型最大能存储的整数：2,147,483,647
    }
    cout << "exit:" << i << endl; //-2,147,483,647   为int类型最小值

    // 例2:
    int a = 500;
    int b = 400;
    int c = 300;
    int d = 200;
    cout << a * b * c * d << endl; // 结果 整数溢出

    return 0;
}