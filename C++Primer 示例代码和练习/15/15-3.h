#include <string>
#include <iostream>
using namespace std;

class Quote
{
public:
    Quote() = default;
    Quote(const string &book, double sales_price) : bookNo(book), price(sales_price) {}
    string isbn() const { return bookNo; }
    // 返回给定数量书籍的销售总额
    // 派生类负责改写并使用不同的折扣计算算法
    virtual double net_price(size_t n) const { return n * price; }
    virtual ~Quote() = default; // 对析构函数动态绑定

private:
    string bookNo; // 书籍的ISBN编号
protected:
    double price = 0.0; // 代表普通状态下不打折的价格
};

// 计算并打印销售给定数量的某种书籍所得的费用
double print_total(ostream &os, const Quote &item, size_t n)
{
    // 根据传入item形参的对象类型调用Quite::new_price
    // 或者Bulk_quote::net_price
    double ret = item.net_price(n);

    os << "ISBN: " << item.isbn() << " # soid: " << n // 调用Quote::isbn
       << " total due: " << ret << endl;

    return ret;
}