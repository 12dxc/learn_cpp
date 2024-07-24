#include <iostream>

int main()
{
    int v1 = 10, v2 = 10;
    // 这是一个完整的输出流，但中间有分号隔开，在c中，分号为一段语句的结束，所以语句未能完整，编译器报错
    // cout << "The sum of" << v1;
    // << 双目运算符需要两个对象
    // << " and " << v2;
    // << " is " << v1 + v2 << endl;

    // 修正：移掉多余分号
    std::cout << "The sum of " << v1
              << " and " << v2
              << " is " << v1 + v2 << std::endl;

    return 0;
}
