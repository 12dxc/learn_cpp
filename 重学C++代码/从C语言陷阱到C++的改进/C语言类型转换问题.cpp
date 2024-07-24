#include <iostream>
using namespace std;

// 1+1/2+1/3+1/4...+1/n
double getSum(int n)
{
    double result = 0.0;
    for (int i = 1; i < n + 1; i++)
    {
        // result += 1.0 / i; // 需要有一个小数，才能使结果为小数,否则会导致精度丢失
        result += static_cast<double>(1) / i; // C++的类型转换，转为小数
    }
    return result;
}

int main()
{
    int array[] = {1, 2, 3};
    int threshold = -1;
    int len = sizeof(array) / sizeof(array)[3];       // 结果为有符号数，需要强转类型
    // 发生了隐式类型转换，导致结果并不是想要的
    if (sizeof(array) / sizeof(array[3]) > static_cast<unsigned>(threshold)) //使用C++的类型转换转为了无符号整数
    // if (len / threshold)
    {
        cout << "正数数组" << endl;
    }
    else
    {
        cout << "负数数组" << endl;
    }

    int n = 0;
    cin >> n;
    cout << getSum(n) << endl;

    int(10);

    return 0;
}