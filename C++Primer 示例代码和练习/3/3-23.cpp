#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    // ����һ������10��������vector����
    for (int i = 1; i <= 10; i++)
    {
        v.push_back(i);
    }
    // ʹ�õ�����������Ԫ�ص�ֵ��Ϊԭ��������
    for (auto it = v.begin(); it != v.end(); it++)
    {
        (*it) *= 2;
    }
    // ���vector���������
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
