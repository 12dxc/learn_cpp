#include <string>
#include <iostream>
using namespace std;
#include "15-3.h"

class Bulk_quote : public Quote // Bulk_quote继承了Quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const string &book, double p, size_t qty, double disc)
        : Quote(book, p), min_qty(qty), discount(disc) {}
    // 覆盖基类的函数版本以实现基于大量购买的折扣策略
    double net_price(size_t cnt) const override
    {
        // 如果达到了购买书籍的某个最低限度值，就可以享受折扣价格了
        if (cnt >= min_qty)
            return cnt * (1 - discount) * price;
        else
            return cnt * price;
    }

private:
    size_t min_qty = 0;    // 适用折扣策略的最低购买量
    double discount = 0.0; // 以小数表示的折扣额
};
