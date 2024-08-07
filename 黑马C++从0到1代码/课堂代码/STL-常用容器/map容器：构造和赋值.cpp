#include <iostream>
using namespace std;
#include <map>

// map휭포 뭐芚뵨립令
void printMap(map<int, int> &m)
{
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << it->first << " value = " << it->second << endl;
    }
    cout << endl;
}

void test01()
{
    // 눼쉔map휭포
    map<int, int> m;

    m.insert(pair<int, int>(4, 40));
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(3, 30));
    m.insert(pair<int, int>(2, 20));

    printMap(m);

    // 옙굔뭐芚
    map<int, int> m2(m);
    printMap(m2);

    // 립令
    map<int, int> m3;
    m3 = m2;
    printMap(m3);
}

int main()
{
    test01();

    system("pause");
    return 0;
}