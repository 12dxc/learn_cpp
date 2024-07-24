#include <iostream>
using namespace std;

int maxValue(int x, int y)
{
    return (x > y) ? x : y;
}
int minValue(int x, int y)
{
    return (x < y) ? x : y;
}
int Add(int x, int y)
{
    return x + y;
}
bool ProcessNum(int x, int y, int (*p)(int a, int b))
{
    // 这种函数叫回调函数
    cout << p(x, y) << endl;
    return true;
}

int main()
{
    int x = 10, y = 20;
    cout << ProcessNum(x, y, maxValue) << endl;
    cout << ProcessNum(x, y, minValue) << endl;
    cout << ProcessNum(x, y, Add) << endl;

    system("pause");
    return 0;
}