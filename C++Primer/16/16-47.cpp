#include <iostream>
using namespace std;

void f(int v1, int &v2)
{
    cout << v1 << " " << ++v2 << endl;
}
// ”翻转“函数
template <typename F, typename T1, typename T2>
void flip1(F f, T1 t1, T2 t2)
{
    f(t2, t1);
}
// 为防止无法更改值，我们使用右值引用
template <typename F, typename T1, typename T2>
void flip2(F f, T1 &&t1, T2 &&t2)
{
    f(t2, t1);
}
// 完美转发版 翻转函数
template <typename F, typename T1, typename T2>
void flip(F f, T1 &&t1, T2 &&t2)
{
    f(forward<T2>(t2), forward<T1>(t1));
}

int main()
{

    system("pause");
    return 0;
}