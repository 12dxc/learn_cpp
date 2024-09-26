#include <iostream>
#include <vector>
using namespace std;

// 查找元素是否在容器中并返回
int find(vector<int> &v, int target)
{

    for (auto it = v.begin(); it != v.end(); it++)
    {
        if (*it == target)
        {
            return *it;
        }
    }
    // 返回-1未找到
    return -1;
}

int main()
{
    vector<int> v = {1, 2, 3, 53, 4, 6, 45, 47, 56, 58, 50};
    cout << find(v, 47) << endl;

    return 0;
}