#include <iostream>
using namespace std;


//递归函数  函数将自身作为子例程调用

//斐波那契数列
//方法一：递归
int Fib(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else {
        return Fib(n - 1) + Fib(n - 2);
    }
}
//方法二：尾递归
int Fib2(int n, int ret0, int ret1)
{
    if (n == 0)
    {
        return ret0;
    }
    else if (n == 1)
    {
        return ret1;
    }

    return Fib2(n - 1, ret1, ret0 + ret1);

}
//方法三：循环
int Fib3(int n)
{
    if (n < 2)
    {
        return n;
    }
    int n0 = 0, n1 = 1;
    int temp;
    for (int i = 2; i <= n; i++)
    {
        temp = n0;
        n0 = n1;
        n1 = temp + n1;
    }
    return n1;
}


int main()
{
    cout << Fib(10) << endl;
    cout << Fib2(10, 0, 1) << endl;
    cout << Fib3(10) << endl;


    system("pause");
    return 0;
}

/*递归的基本法则：
*   1、基准情形：无需递归就能解出
*   2、不断推进：每一次递归调用都必须使求解状况朝接近基准情形的方向推进
*   3、设计法则：假设所有的递归调用都能运行
*   4、合成效益法则：求解一个问题的同一实例时，切勿在不同的递归调用中做重复的工作
* 递归的缺点：
*   A.空间上需要开辟大量的栈空间
*   B.时间上可能需要有大量的重复运算
* 递归的优化：
*   1、尾递归，所有递归形式的调用出现在函数末尾
*   2、使用循环代替
*   3、使用动态规划，空间换时间
*/