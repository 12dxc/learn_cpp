#include <iostream>
using namespace std;
#include <set>

// set容器 查找和统计

void printSet(set<int> &s)
{
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    set<int> s1;

    // 插入
    s1.insert(10);
    s1.insert(40);
    s1.insert(30);
    s1.insert(20);

    // 查找
    set<int>::iterator pos = s1.find(30); // find() 返回迭代器
    if (pos != s1.end())
    {
        cout << "找到元素：" << *pos << endl;
    }
    else
    {
        cout << "未找到元素" << endl;
    }

    // 统计30的个数
    int num = s1.count(30);
    // 对于set而言，统计的结果 要么是0 要么是1
    cout << "num = " << num << endl;
}

int main()
{
    test01();

    system("pause");
    return 0;
}