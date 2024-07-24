#include <iostream>
using namespace std;

int test(int a)
{
    return a;
}
namespace two   // 用namespace关键字声明命名空间
{
    int test(int a)
    {
        return a + 1;
    }
};



int main()
{
    int(*p)(int);
    p = test;
    int result = (*p)(0);
    cout << result << endl;

    result = two::test(0);   //用标识符来使用命名空间内部的代码
    cout << result << endl;



    system("pause");
    return 0;
}