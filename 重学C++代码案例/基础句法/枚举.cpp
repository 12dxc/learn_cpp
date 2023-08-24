#include <iostream>
using namespace std;


int main()
{
    enum wT { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };
    wT weekday;
    weekday = Monday;
    weekday = Tuesday;
    //weekday = 1;   //不能直接给int值，只能赋值成wT定义好的类型值
    cout << weekday << endl;
    //Monday = 0;    //类型值不能做左值
    int a = Wednesday;    //枚举变量可直接赋给非枚举变量
    cout << a << endl;

    system("pause");
    return 0;
}