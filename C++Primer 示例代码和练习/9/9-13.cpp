#include <iostream>
#include <vector>
#include <list>
using namespace std;

// �����俽��
int main()
{
    list<int> l{1, 2, 3, 4, 5};
    // �������Ͳ�ͬ��ʹ�õ�������Χ����
    vector<double> v(l.begin(), l.end());

    vector<int> v2{5, 4, 3, 2, 1};
    // ������ͬ��ֱ���ÿ�������
    vector<int> v3(v2);

    return 0;
}