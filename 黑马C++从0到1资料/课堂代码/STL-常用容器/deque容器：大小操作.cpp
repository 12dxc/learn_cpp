#include <iostream>
using namespace std;
#include <deque>

// deque���� ��С����

void printDeque(const deque<int> &d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        //*it = 100;   �����е����ݲ������޸���
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    // Ĭ�Ϲ�����ʽ
    deque<int> d1;

    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);

    if (d1.empty()) // �ж������Ƿ�Ϊ��
    {
        cout << "d1Ϊ��" << endl;
    }
    else
    {
        cout << "d1��Ϊ��" << endl;
        cout << "d1�Ĵ�СΪ��" << d1.size() << endl;
        // dequeû�������ĸ���
    }

    // ����ָ����С
    // d1.resize(15);
    d1.resize(15, 1);
    printDeque(d1);

    d1.resize(5);
    printDeque(d1);
}

int main()
{
    test01();

    system("pause");
    return 0;
}