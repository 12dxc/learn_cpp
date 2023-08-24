#include <iostream>
using namespace std;

int g_a[1000];  //全局数组，记录

//动态规划
int Fib(int n)
{
    g_a[0] = 0;
    g_a[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (g_a[i] == 0)
        {
            g_a[i] = g_a[i - 1] + g_a[i - 2];
        }
    }
    return g_a[n];
}

int main()
{

    cout << Fib(10) << endl;

    system("pause");
    return 0;
}

