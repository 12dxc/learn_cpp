#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// 常用查找算法  binary_search
void test01()
{
    vector<int> v;

    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    // 查找容器中是否有9
    // 注意：容器必须是有序序列
    bool ret = binary_search(v.begin(), v.end(), 9);
    if (ret)
    {
        cout << "找到元素" << endl;
    }
    else
    {
        cout << "未找到" << endl;
    }
}

int main()
{

    test01();
    system("pause");
    return 0;
}