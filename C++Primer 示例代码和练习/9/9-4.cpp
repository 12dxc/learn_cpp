#include <iostream>
#include <vector>
using namespace std;

// 查找元素是否在容器中
bool find(vector<int> &v, int target)
{

    for (auto it = v.begin(); it != v.end(); it++)
    {
        if (*it == target)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<int> v = {1, 2, 3, 53, 4, 6, 45, 47, 56, 58, 50};
    cout << find(v, 1) << endl;

    return 0;
}