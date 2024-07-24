#include <iostream>
using namespace std;
#include "Sales_item.h"

int main()
{
    cout << "请输入两本拥有相同的ISBN号的书、售出的册数以及销售价格" << endl;
    Sales_item book1, book2;
    cin >> book1 >> book2;
    if (book1.isbn() == book2.isbn())
    {
        cout << book1 + book2 << endl; // 和为 总销售额相加且单价求平均
    }
    else
    {
        cout << "书号不相同" << endl;
    }
    return 0;
}
