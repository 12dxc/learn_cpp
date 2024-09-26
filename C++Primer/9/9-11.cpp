#include <iostream>
#include <vector>
using namespace std;

vector<int> other_vec{1, 2, 3, 4, 5, 6, 7};

// vector 的6种创建和初始化方式
int main()
{
    // 默认
    vector<int> v1; // 0
    // 指定容量
    vector<int> v3(10); // 0
    // 显示指定值 初始化
    vector<int> v2{1, 2, 3, 4, 5}; // 1,2,3,4,5
    // 给定数量和元素，有n个相同元素
    vector<int> v4(10, 1); // 1
    // 拷贝
    vector<int> v5(other_vec); // 1, 2, 3, 4, 5, 6, 7
    // 范围拷贝
    vector<int> v6(other_vec.begin(), other_vec.begin() + 5); // 1, 2, 3, 4, 5

    return 0;
}