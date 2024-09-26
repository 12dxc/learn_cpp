#include <iostream>
using namespace std;
#include "Sales_item.h"

int main()
{
    cout << "请输入ISBN号、售出的册数以及销售价格" << endl;
    for (Sales_item book; cin >> book; cout << book << endl)
        ;
    return 0;
}
