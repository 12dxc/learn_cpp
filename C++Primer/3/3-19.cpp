#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    // 定义一个含有10个42的vector对象
    // 1、列表初始化
    vector<int> v = {42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
    // 2、构造函数初始化
    vector<int> v2(10, 42);
    // 3、for循环追加元素
    vector<int> v3;
    for (int i = 0; i < 10; i++)
        v3.push_back(42);

    // 其中第二种方法最优，代码量最小

    return 0;
}
