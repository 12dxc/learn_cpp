#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
    // 将ia拷贝到list和vector
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    list<int> l(ia, end(ia));
    vector<int> v(l.begin(), l.end());

    // 使用单迭代器版的earselist删除奇数元素，vector删除偶数元素
    for (auto it = l.begin(); it != l.end();)
    {
        if (*it % 2 != 0)
        {
            // earse返回下一个元素迭代器，相当于迭代
            it = l.erase(it);
        }
        else
        {
            // 如果不是奇数则迭代
            it++;
        }
    }
    for (auto it = v.begin(); it != v.end();)
    {
        if (*it % 2 == 0)
        {
            it = v.erase(it);
        }
        else
        {
            it++;
        }
    }

    for (auto i : l)
        cout << i
             << " ";
    cout << endl;
    for (auto i : v)
        cout << i
             << " ";
    cout << endl;

    return 0;
}