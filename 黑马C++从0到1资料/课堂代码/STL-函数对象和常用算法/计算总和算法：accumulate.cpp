#include <iostream>
using namespace std;
#include <vector>
#include <numeric>

// 常用算术生成算法  accumulate  计算容器元素累计总和
void test01()
{
    vector<int> v;
    for (int i = 0; i <= 100; i++)
    {
        v.push_back(i);
    }

    // 计算容器中元素的总和
    // 参数3 起始累加值
    int total = accumulate(v.begin(), v.end(), 0);
    cout << "total = " << total << endl;
}

int main()
{

    test01();

    system("pause");
    return 0;
}