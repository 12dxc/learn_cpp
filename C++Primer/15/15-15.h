#include <string>
#include <iostream>
using namespace std;

class Quote
{
public:
    // 该虚函数返回当前对象的一份动态分配的拷贝
    virtual Quote *clone() const & { return new Quote(*this); }
    virtual Quote *clone() && { return new Quote(move(*this)); }

    Quote() = default;
    Quote(const std::string &b, double p)
        : bookNo(b), price(p) {}

    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const { return n * price; }

    virtual ~Quote() = default;

private:
    std::string bookNo;

protected:
    double price = 0.0;
};

class Disc_quote : public Quote
{
public:
    Disc_quote() = default;
    Disc_quote(const string &book, double price, size_t qty, double disc)
        : Quote(book, price), quantity(qty), discount(disc) {}
    double net_price(size_t) const = 0;

protected:
    size_t quantity = 0;   // 折扣适用的购买量
    double discount = 0.0; // 表示折扣的小数值
};

// 当同一书籍的销售量超过某个值时启用折扣
// 折扣的值是一个小于1的正的小数值，以此来降低正常的销售价格
class Bulk_quote : public Disc_quote
{
public:
    virtual Bulk_quote *clone() const & { return new Bulk_quote(*this); }
    virtual Bulk_quote *clone() && { return new Bulk_quote(move(*this)); }

    Bulk_quote() = default;
    Bulk_quote(const string &book, double price, size_t qty, double disc)
        : Disc_quote(book, price, qty, disc) {}
    double net_price(size_t) const override;
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