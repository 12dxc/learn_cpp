#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// ���ò����㷨  adjacent_find
void test01()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(5);
    v.push_back(2);
    v.push_back(4);
    v.push_back(4);
    v.push_back(3);

    // ���������ظ�Ԫ��
    vector<int>::iterator it = adjacent_find(v.begin(), v.end());
    if (it == v.end())
    {
        cout << "�Ҳ���!" << endl;
    }
    else
    {
        cout << "�ҵ������ظ�Ԫ��Ϊ:" << *it << endl;
    }
}

int main()
{

    test01();
    system("pause");
    return 0;
}