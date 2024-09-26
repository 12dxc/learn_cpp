#include <iostream>
using namespace std;

void print_range(int lnum, int rnum)
{
    if (lnum > rnum) // 如果输入的左数比右数大，则交换传参，求范围内所有数
    {
        print_range(rnum, lnum);
        return;
    }
    int num;
    while (lnum <= rnum) // 当左数小于等于右数时，意味着已得到它们之间的所有数
    {
        cout << lnum << " ";
        ++lnum;
    }
    cout << endl;
}

int main()
{
    cout << "请输入两个整数:" << endl;
    int lnum = 0, rnum = 0;
    cin >> lnum >> rnum;

    print_range(lnum, rnum);

    return 0;
}
