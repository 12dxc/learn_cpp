#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// 常用集合算法  set_intersection  交集
void myPrint(int val)
{
    cout << val << " ";
}
void test01()
{
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);     // 0~9
        v2.push_back(i + 5); // 5~14
    }

    vector<int> vTarget;
    //目标容器开辟空间需要从两个容器中取最小值
    vTarget.resize(min(v1.size(), v2.size()));

    // 获取交集  返回值是交集的最后一个元素
    vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

    for_each(vTarget.begin(), itEnd, myPrint);
    cout << endl;
}

int main()
{

    test01();

    system("pause");
    return 0;
}