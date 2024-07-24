#include <iostream>
using namespace std;
#include <set>

// set容器 大小和交换

void printSet(set<int> &s)
{
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 大小
void test01()
{
    set<int> s1;

    s1.insert(10);
    s1.insert(40);
    s1.insert(30);
    s1.insert(20);

    // 打印容器
    printSet(s1);

    // 判断是否为空
    if (s1.empty())
    {
        cout << "s1为空" << endl;
    }
    else
    {
        cout << "s1不为空" << endl;
        cout << "s1的元素个数为：" << s1.size() << endl;
    }
}

// 交换
void test02()
{
    set<int> s1;

    s1.insert(10);
    s1.insert(40);
    s1.insert(30);
    s1.insert(20);

    set<int> s2;

    s2.insert(100);
    s2.insert(400);
    s2.insert(300);
    s2.insert(200);

    cout << "交换前：" << endl;
    printSet(s1);
    printSet(s2);

    s1.swap(s2);

    cout << "交换后：" << endl;
    printSet(s1);
    printSet(s2);
}

int main()
{
    test01();
    test02();

    system("pause");
    return 0;
}