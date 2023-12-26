#include <iostream>
using namespace std;

int main()
{
    int sum = 0, num = 0;
    while (cin >> num)
    {
        sum += num;
    }
    // windows 输入文件结束符的方式是：ctrl+Z -> Enter

    cout << sum;
    return 0;
}
