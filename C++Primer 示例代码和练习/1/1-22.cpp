#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item total; // 保存和的变量
    // 读入第一条交易记录，并确保有数据可以处理
    if (std::cin >> total)
    {
        Sales_item trans; // 保存下一条交易记录的变量
        // 读入并处理剩余交易记录
        while (std::cin >> trans)
        {
            // 如果仍在处理相同的书
            if (total.isbn() == trans.isbn())
                // 更新销售额
                total += trans;
            // 否则打印前一本书的结果
            else
            {
                std::cout << total << std::endl;
                total = trans; // total 表示下一本书的销售额
            }
        }
        std::cout << total << std::endl; // 打印最后一本书的结果
    }
    else
    {
        // 无输入，发出警告
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}
