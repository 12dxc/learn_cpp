#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// ���ÿ������滻�㷨 replace ��������ָ����Χ�ľ�Ԫ���޸�Ϊ��Ԫ��
void myPrint(int val)
{
    cout << val << " ";
}
void test01()
{
    vector<int> v;
    v.push_back(20);
    v.push_back(30);
    v.push_back(20);
    v.push_back(40);
    v.push_back(50);
    v.push_back(10);
    v.push_back(20);

    cout << "�滻ǰ��" << endl;
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;

    // ����3��Ҫ�滻����Ԫ�أ�����4��Ҫ�滻����Ԫ��
    replace(v.begin(), v.end(), 20, 2000);
    cout << "�滻��" << endl;
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
}

int main()
{

    test01();

    system("pause");
    return 0;
}