#include <iostream>
using namespace std;

int main()
{
    int a = 123;
    int *b = &a;
    // 指向指针的指针
    int **c = &b;

    // 单目运算符，都具有从右向左的结合性
    cout << *c << endl;  // 可间接访问&b的值
    cout << **c << endl; // 可间接访问*b和a的值

    return 0;
}