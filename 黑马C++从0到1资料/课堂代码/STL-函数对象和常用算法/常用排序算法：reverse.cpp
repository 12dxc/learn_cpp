#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <ctime>

// 常用排序算法 revese  将容器内元素进行反转

void myPrint(int val)
{
    cout << val << " ";
}
void test01()
{
    vector<int> v;

    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    cout << "反转前：" << endl;
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;

    cout << "反转后：" << endl;
    reverse(v.begin(), v.end());
    for_each(v.begin(), v.end(), myPrint);
}

int main()
{

    test01();

    system("pause");
    return 0;
}