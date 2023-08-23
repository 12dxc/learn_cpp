#include <iostream>
using namespace std;
#include <map>

// map���� ��С�ͽ���

void printMap(map<int, int> &m)
{
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << it->first << " value = " << it->second << endl;
    }
    cout << endl;
}

// ��С
void test01()
{
    // ����map����
    map<int, int> m;

    m.insert(pair<int, int>(4, 40));
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(3, 30));
    m.insert(pair<int, int>(2, 20));

    if (m.empty())
    {
        cout << "mΪ��" << endl;
    }
    else
    {
        cout << "m��Ϊ��" << endl;
        cout << "m��Ԫ�ظ���Ϊ��" << m.size() << endl;
    }
}
// ����
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

    cout << "����ǰ��" << endl;
    printMap(m1);
    printMap(m2);
    cout << "������" << endl;
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