#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// 常用拷贝和替换算法 replace_if  将区间内满足条件的元素，替换成指定元素
void myPrint(int val)
{
    cout << val << " ";
}
class Greater30
{
public:
    bool operator()(int v)
    {
        return v >= 30;
    }
};
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

    // 将大于等于30的替换为3000
    replace_if(v.begin(), v.end(), Greater30(), 3000);

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