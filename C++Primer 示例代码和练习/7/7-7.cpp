#include <iostream>
using namespace std;
#include "7-6.h"

int main()
{
     Sales_data total;
     if (read(cin, total))
     {
          Sales_data trans;
          while (read(cin, trans))
          {
               if (total.isbn() == trans.isbn())
               {
                    // ���±���total��ǰ��ֵ
                    total.combine(trans);
               }
               else
               {
                    // ������
                    print(cout, total);
                    total = trans; // ������һ����
               }
          }
          // ������һ������
          print(cout, total);
     }
     else // û�������κ���Ϣ
     {
          // ֪ͨ�û�
          cerr << "No data?!" << endl;
          return -1;
     }

     return 0;
}