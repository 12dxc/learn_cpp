#include <iostream>
using namespace std;

// 使用for循环重写1.4.1练习

int main()
{
    // 1.9
    int sum = 0;
    for (int i = 50; i <= 100; i++)
    {
        sum += i;
    }
    cout << "50~100的和为:" << sum << endl;

    // 1.10
    sum = 0;
    for (int i = 10; i != 0; i--)
    {
        sum += i;
    }
    cout << "10~0的和为:" << sum << endl;

    // 1.11
    sum = 0;
    int lnum = 0, rnum = 0;
    cout << "请输入两个数:" << endl;
    cin >> lnum >> rnum;
    cout << lnum << "~" << rnum << "范围内的数有:" << endl;
    for (int i = lnum; i <= rnum; i++)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
