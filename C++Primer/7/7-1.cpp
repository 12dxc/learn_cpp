#include <iostream>
using namespace std;

struct Sales_data
{
     // 书号
     string bookNo;
     // 销量
     unsigned units_sold = 0;
     // 销售额
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
                    // 更新变量total当前的值
                    total.units_sold = trans.units_sold;
                    total.revenue = total.revenue;
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