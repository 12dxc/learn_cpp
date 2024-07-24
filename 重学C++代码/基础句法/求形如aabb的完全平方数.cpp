#include <iostream>
using namespace std;
#include<math.h>

int main()
{
    int n = 0;
    double m = 0;
    //aabb的完全平方数
    for (size_t a = 1; a < 10; a++)
    {
        for (size_t b = 0; b < 10; b++)
        {
            n = a * 1100 + b * 11;  //aabb
            m = sqrt(n);
            if (m - int(m) < 0.00000001)  //检测是否是整数
            {
                cout << n << endl;
            }
        }
    }

    int high, low;
    //更好的解决方法
    for (size_t i = 1;; i++)
    {
        n = i * i;
        //确定范围
        if (n < 1000)
        {
            continue;   //继续下一次循环
        }
        if (n > 9999)
        {
            break;      //退出循环
        }

        high = n / 100;   //取高位的数
        low = n % 100;    //取低位的数

        if (high / 10 == high % 10 && low / 10 == low & 10)
        {
            cout << n << endl;
        }
    }

    system("pause");
    return 0;
}