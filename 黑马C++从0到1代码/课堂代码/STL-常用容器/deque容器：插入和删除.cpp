#include <iostream>
using namespace std;
#include <deque>

// deque容器 插入和删除

void printDeque(const deque<int> &d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        //*it = 100;   容器中的数据不可以修改了
        cout << *it << " ";
    }
    cout << endl;
}

// 两端操作
void test01()
{
    deque<int> d1;

    // 尾插
    d1.push_back(10);
    d1.push_back(20);

    // 头插
    d1.push_front(100);
    d1.push_front(200);

    printDeque(d1); // 200 100 10 20

    // 尾删
    d1.pop_back();
    printDeque(d1); // 200 100 10

    // 头删
    d1.pop_front();
    printDeque(d1); // 100 10
}

// 指定位置操作
void test02()
{
    deque<int> d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);
    // 200 100 10 20
    printDeque(d1);

    // insert插入
    d1.insert(d1.begin(), 1000);
    // 1000 200 100 10 20
    printDeque(d1);

    d1.insert(d1.begin(), 2, 10000);
    // 10000 10000 1000 200 100 10 20
    printDeque(d1);

    // 按照区间进行插入
    deque<int> d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);

    d1.insert(d1.begin(), d2.begin(), d2.end());
    // 1 2 3 10000 10000 1000 200 100 10 20
    printDeque(d1);
}

// 删除和清空
void test03()
{
    deque<int> d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);

    // 删除
    deque<int>::iterator it = d1.begin();
    it++;
    d1.erase(it);
    // 200 10 20
    printDeque(d1);

    // 按区间的方式删除
    d1.erase(d1.begin(), d1.end());

    // 清空
    d1.clear();
    printDeque(d1);
}

int main()
{
    test01();
    test02();
    test03();

    system("pause");
    return 0;
}