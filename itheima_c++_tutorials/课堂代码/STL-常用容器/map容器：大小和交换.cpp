#include <iostream>
using namespace std;
#include <map>

// map容器 大小和交换

void printMap(map<int, int> &m)
{
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << it->first << " value = " << it->second << endl;
    }
    cout << endl;
}

// 大小
void test01()
{
    // 创建map容器
    map<int, int> m;

    m.insert(pair<int, int>(4, 40));
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(3, 30));
    m.insert(pair<int, int>(2, 20));

    if (m.empty())
    {
        cout << "m为空" << endl;
    }
    else
    {
        cout << "m不为空" << endl;
        cout << "m的元素个数为：" << m.size() << endl;
    }
}
// 交换
void test02()
{
    map<int, int> m1;

    m1.insert(pair<int, int>(4, 40));
    m1.insert(pair<int, int>(1, 10));
    m1.insert(pair<int, int>(3, 30));
    m1.insert(pair<int, int>(2, 20));

    map<int, int> m2;

    m2.insert(pair<int, int>(50, 5));
    m2.insert(pair<int, int>(70, 7));
    m2.insert(pair<int, int>(60, 6));
    m2.insert(pair<int, int>(80, 8));

    cout << "交换前：" << endl;
    printMap(m1);
    printMap(m2);
    cout << "交换后" << endl;
    m1.swap(m2);
    printMap(m1);
    printMap(m2);
}

int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}