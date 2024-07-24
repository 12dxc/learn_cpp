#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// 常用拷贝和替换算法 replace 将容器内指定范围的旧元素修改为新元素
void myPrint(int val)
{
    cout << val << " ";
}
void test01()
{
    vector<int> v;
    v.push_back(20);
    v.push_back(30);
    v.push_back(20);
    v.push_back(40);
    v.push_back(50);
    v.push_back(10);
    v.push_back(20);

    cout << "替换前：" << endl;
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;

    // 参数3是要替换的老元素，参数4是要替换的新元素
    replace(v.begin(), v.end(), 20, 2000);
    cout << "替换后：" << endl;
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
}

int main()
{

    test01();

    system("pause");
    return 0;
}