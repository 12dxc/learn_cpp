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
                    // 更新变量total当前的值
                    total.combine(trans);
               }
               else
               {
                    // 输出结果
                    print(cout, total);
                    total = trans; // 处理下一本书
               }
          }
          // 输出最后一条交易
          print(cout, total);
     }
     else // 没有输入任何信息
     {
          // 通知用户
          cerr << "No data?!" << endl;
          return -1;
     }

     return 0;
}