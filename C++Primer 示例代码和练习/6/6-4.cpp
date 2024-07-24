#include <iostream>
using namespace std;

// 求数阶乘
int fact(int i)
{

     return i > 1 ? i * fact(i - 1) : 1;
}
int main()
{
     cout << "请输入一个数字:" << endl;
     int n;
     cin >> n;
     cout << n << " 的阶乘为: " << fact(n) << endl;

     system("pause");
     return 0;
}
