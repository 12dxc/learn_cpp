#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// 常用集合算法  set_difference  差集
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

    // 创建目标容器
    vector<int> vTarget;
    // 给目标容器开辟空间
    // 最特殊情况，没有交集，故取两容器最大值作为目标容器空间大小
    vTarget.resize(max(v1.size(), v2.size()));

    cout << "v1和v2的差集为：" << endl;
    vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

    for_each(vTarget.begin(), itEnd, myPrint);
    cout << endl;

    cout << "v2和v1的差集为：" << endl;
    itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());

    for_each(vTarget.begin(), itEnd, myPrint);
    cout << endl;
}

int main()
{

    test01();

    system("pause");
    return 0;
}