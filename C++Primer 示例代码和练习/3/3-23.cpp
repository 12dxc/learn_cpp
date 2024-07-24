#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    // 创建一个含有10个整数的vector对象
    for (int i = 1; i <= 10; i++)
    {
        v.push_back(i);
    }
    // 使用迭代器将所有元素的值变为原来的两倍
    for (auto it = v.begin(); it != v.end(); it++)
    {
        (*it) *= 2;
    }
    // 输出vector对象的内容
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
