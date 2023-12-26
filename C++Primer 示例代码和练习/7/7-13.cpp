#include <iostream>
using namespace std;
#include "7-12.h"

int main()
{
     Sales_data total(cin);
     if (!total.isbn().empty())
     {
          istream &is = cin;
          while (is)
          {
               Sales_data trans(is);
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