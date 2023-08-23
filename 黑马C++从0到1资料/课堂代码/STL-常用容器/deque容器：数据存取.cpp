#include <iostream>
using namespace std;
#include <deque>

// deque容器 数据存取

void test01()
{
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_front(100);
    d.push_front(200);
    d.push_front(300);

    // 通过[]访问元素
    for (int i = 0; i < d.size(); i++)
    {
        // 300 200 100 10 20 30
        cout << d[i] << " ";
    }
    cout << endl;

    // 通过at访问元素
    for (int i = 0; i < d.size(); i++)
    {
        // 300 200 100 10 20 30
        cout << d.at(i) << " ";
    }
    cout << endl;

    // 访问首尾元素
    cout << "d的第一个元素为：" << d.front() << endl;
    cout << "d的最后一个元素为：" << d.back() << endl;
}

int main()
{
    test01();
    system("pause");
    return 0;
}