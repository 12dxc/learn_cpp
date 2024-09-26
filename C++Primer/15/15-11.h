#include <string>
#include <iostream>
using namespace std;

class Quote
{
public:
    Quote() = default;
    Quote(const std::string &b, double p)
        : bookNo(b), price(p) {}

    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const { return n * price; }

    virtual ~Quote() = default;

    void debug() const
    {
        cout << "这个类对象的数据成员有:\n"
             << "bookNo= " << this->bookNo << " "
             << "price= " << this->price << " ";
    }

private:
    std::string bookNo;

protected:
    double price = 0.0;
};