#include <iostream>
using namespace std;

struct Sales_data
{
     // ���
     string bookNo;
     // ����
     unsigned units_sold = 0;
     // ���۶�
     double revenue = 0.0;
};

int main()
{
     Sales_data total;
     if (cin >> total.bookNo, cin >> total.units_sold, cin >> total.revenue)
     {
          Sales_data trans;
          while (cin >> trans.bookNo, cin >> trans.units_sold, cin >> trans.revenue)
          {
               if (total.bookNo == trans.bookNo)
               {
                    // ���±���total��ǰ��ֵ
                    total.units_sold = trans.units_sold;
                    total.revenue = total.revenue;
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