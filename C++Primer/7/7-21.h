#include <string>
#include <iostream>
using namespace std;

struct Sales_data
{
     friend istream &read(istream &is, Sales_data &item);
     friend ostream &print(ostream &os, const Sales_data &item);
     friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

public:
     // 新增的构造函数
     Sales_data() = default;
     Sales_data(const string &s) : bookNo(s) {}
     Sales_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {}
     // 输入流初始化构造函数
     Sales_data(istream &) { read(cin, *this); }

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
private:
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
// 与类相关的非成员函数
//  相加操作
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
     Sales_data sum = lhs; // 把lhs的数据成员拷贝给sum
     sum.combine(rhs);
     return sum;
}
// 输入操作
istream &read(istream &is, Sales_data &item)
{
     // 设置单价
     double price = 0;
     is >> item.bookNo >> item.units_sold >> price;
     // 为销售额赋值  即输入的单价 * 销量
     item.revenue = price * item.units_sold;

     return is;
}
// 输出操作
ostream &print(ostream &os, const Sales_data &item)
{
     os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price() << endl;
     return os;
}
