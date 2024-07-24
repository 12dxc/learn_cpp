#include <iostream>
using namespace std;
#include <deque>
#include <algorithm> //标准算法头文件

void printDeque(const deque<int> &d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// degue容器 排序
void test01()
{
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_front(100);
    d.push_front(200);
    d.push_front(300);

    // 300 200 100 10 20 30
    printDeque(d);

    // 排序  默认排序规则  从小到大 升序
    // 支持随机访问迭代器的容器，都可以利用sort算法直接进行排序
    sort(d.begin(), d.end());
    cout << "排序后：" << endl;
    printDeque(d);
}

int main()
{
    test01();
    system("pause");
    return 0;
}