#include <iostream>
using namespace std;
#include <vector>
#include <numeric>

// �������������㷨  accumulate  ��������Ԫ���ۼ��ܺ�
void test01()
{
    vector<int> v;
    for (int i = 0; i <= 100; i++)
    {
        v.push_back(i);
    }

    // ����������Ԫ�ص��ܺ�
    // ����3 ��ʼ�ۼ�ֵ
    int total = accumulate(v.begin(), v.end(), 0);
    cout << "total = " << total << endl;
}

int main()
{

    test01();

    system("pause");
    return 0;
}