#include <iostream>
#include <vector>
#include <list>
using namespace std;

// 容器间拷贝
int main()
{
    list<int> l{1, 2, 3, 4, 5};
    // 容器类型不同，使用迭代器范围拷贝
    vector<double> v(l.begin(), l.end());

    vector<int> v2{5, 4, 3, 2, 1};
    // 类型相同，直接用拷贝函数
    vector<int> v3(v2);

    return 0;
}