#include <iostream>
using namespace std;
#include <vector>
#include <numeric>
#include <algorithm>

class myPrint
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};

// 常用算术生成算法  fill  填充：向容器中填充指定的元素
void test01()
{
    vector<int> v;
    v.resize(10);

    // 后期重新填充
    fill(v.begin(), v.end(), 1000);

    for_each(v.begin(), v.end(), myPrint());
    cout << endl;
}

int main()
{

    test01();

    system("pause");
    return 0;
}