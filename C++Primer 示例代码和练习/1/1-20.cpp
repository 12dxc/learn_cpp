#include <iostream>
using namespace std;
#include "Sales_item.h"

int main()
{
    cout << "������ISBN�š��۳��Ĳ����Լ����ۼ۸�" << endl;
    for (Sales_item book; cin >> book; cout << book << endl)
        ;
    return 0;
}
