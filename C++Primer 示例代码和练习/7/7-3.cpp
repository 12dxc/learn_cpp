#include <iostream>
using namespace std;
#include "7-2.h"

int main()
{
     Sales_data total;
     if (cin >> total.bookNo, cin >> total.units_sold, cin >> total.revenue)
     {
          Sales_data trans;
          while (cin >> trans.bookNo, cin >> trans.units_sold, cin >> trans.revenue)
          {
               if (total.isbn() == trans.isbn())
               {
                    // ���±���total��ǰ��ֵ
                    total.combine(trans);
               }
               else
               {
                    // ������
                    cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
                    total = trans; // ������һ����
               }
          }
          // ������һ������
          cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
     }
     else // û�������κ���Ϣ
     {
          // ֪ͨ�û�
          cerr << "No data?!" << endl;
          return -1;
     }

     return 0;
}