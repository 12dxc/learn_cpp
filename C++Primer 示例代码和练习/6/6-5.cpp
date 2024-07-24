#include <iostream>
using namespace std;

// 求数阶乘
int absolute_value(int i)
{

     return i > 0 ? i : -i; // 负数再加一个负号即可转为正数
}
int main()
{
     cout << "请输入一个数字:" << endl;
     int n;
     cin >> n;
     cout << n << " 的绝对值: " << absolute_value(n) << endl;

     system("pause");
     return 0;
}
