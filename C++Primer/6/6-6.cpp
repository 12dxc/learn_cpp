#include <iostream>
using namespace std;

// 例子
int count_add(int n) // n是形参
{
     static int ctr = 0; // ctr 是局部静态变量
     ctr += n;
     return ctr;
}

int main()
{
     for (int i = 0; i != 10; ++i) // i 是局部变量
          cout << count_add(i) << endl;

     return 0;
}