#include <iostream>
using namespace std;
#include <deque>

// deque���� ���ݴ�ȡ

void test01()
{
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_front(100);
    d.push_front(200);
    d.push_front(300);

    // ͨ��[]����Ԫ��
    for (int i = 0; i < d.size(); i++)
    {
        // 300 200 100 10 20 30
        cout << d[i] << " ";
    }
    cout << endl;

    // ͨ��at����Ԫ��
    for (int i = 0; i < d.size(); i++)
    {
        // 300 200 100 10 20 30
        cout << d.at(i) << " ";
    }
    cout << endl;

    // ������βԪ��
    cout << "d�ĵ�һ��Ԫ��Ϊ��" << d.front() << endl;
    cout << "d�����һ��Ԫ��Ϊ��" << d.back() << endl;
}

int main()
{
    test01();
    system("pause");
    return 0;
}