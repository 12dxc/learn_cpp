#include <string>
using namespace std;

struct Sales_data
{
     // 成员函数
     // 获取书号
     string isbn() const // 加const使得内部定义不可修改数据
     {
          return this->bookNo;
     }

     // 将一个对象加到另一个对象
     Sales_data &combine(const Sales_data &rhs);

     // 获取售出书籍的平均价格
     double avg_price() const;

     // 数据成员
     //  书号
     string bookNo;
     // 销量
     unsigned units_sold = 0;
     // 销售额
     double revenue = 0.0;
};

// 成员函数类外定义  需指定作用域
double Sales_data::avg_price() const
{
     if (units_sold)
     {
          return revenue / units_sold;
     }
     else
     {
          return 0;
     }
}
Sales_data &Sales_data::combine(const Sales_data &rhs)
{
     units_sold += rhs.units_sold;
     revenue += rhs.revenue;
     return *this;
}
