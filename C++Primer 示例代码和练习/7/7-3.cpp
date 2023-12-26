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
                    // 更新变量total当前的值
                    total.combine(trans);
               }
               else
               {
                    // 输出结果
                    cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
                    total = trans; // 处理下一本书
               }
          }
          // 输出最后一条交易
          cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
     }
     else // 没有输入任何信息
     {
          // 通知用户
          cerr << "No data?!" << endl;
          return -1;
     }

     return 0;
}