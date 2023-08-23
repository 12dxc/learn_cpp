#include <iostream>
using namespace std;
#include <vector>
#include <algorithm> //��׼�㷨ͷ�ļ�

// vector����������õ���������

void myPrint(int val)
{
    cout << val << " ";
}

void test01()
{
    // ������һ��vector����������
    vector<int> v;

    // �������в�������
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    // ͨ�������������������е�����
    vector<int>::iterator itBegin = v.begin(); // ��ʼ��������ָ�������е�һ��Ԫ�ص�λ��
    vector<int>::iterator itEnd = v.end();     // ������������ָ�����������һ��Ԫ�ص���һ��λ��

    // ��һ�ֱ�����ʽ
    cout << "��һ�ֱ�����ʽ" << endl;
    while (itBegin != itEnd)
    {
        cout << *itBegin << " ";
        itBegin++;
    }
    cout << endl;

    // �ڶ��ֱ�����ʽ
    cout << "�ڶ��ֱ�����ʽ" << endl;
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // �����ֱ�����ʽ  ����STL�ṩ�ı����㷨
    cout << "�����ֱ�����ʽ" << endl;
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
}

int main()
{
    test01();
    system("pause");
    return 0;
}