#include <iostream>
using namespace std;
#include "Sales_item.h"

int main()
{
    cout << "����������ӵ����ͬ��ISBN�ŵ��顢�۳��Ĳ����Լ����ۼ۸�" << endl;
    Sales_item book1, book2;
    cin >> book1 >> book2;
    if (book1.isbn() == book2.isbn())
    {
        cout << book1 + book2 << endl; // ��Ϊ �����۶�����ҵ�����ƽ��
    }
    else
    {
        cout << "��Ų���ͬ" << endl;
    }
    return 0;
}
