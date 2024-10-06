#include <iostream>
using namespace std;
#include <deque>

// deque容器 大小操作

void printDeque(const deque<int> &d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        //*it = 100;   容器中的数据不可以修改了
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    // 默认构造形式
    deque<int> d1;

    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);

    if (d1.empty()) // 判断容器是否为空
    {
        cout << "d1为空" << endl;
    }
    else
    {
        cout << "d1不为空" << endl;
        cout << "d1的大小为：" << d1.size() << endl;
        // deque没有容量的概念
    }

    // 重新指定大小
    // d1.resize(15);
    d1.resize(15, 1);
    printDeque(d1);

    d1.resize(5);
    printDeque(d1);
}

int main()
{
    test01();

    system("pause");
    return 0;
}