#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // ����һ����������ÿ�����������ĺ����
    vector<int> v;
    int i;
    while (cin >> i)
    {
        v.push_back(i);
    }

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] + v[i + 1] << endl;
    }
    cout << "---------------------------------" << endl;

    // ������� 1~n-1,2~n-2... �ĺ�
    int m = 0;            // ��ʼ�±�
    int n = v.size() - 1; // ĩβ�±�
    while (m < n)         // ����ʼ�±곬��ĩβ�±꣬˵������������������
    {
        cout << v[m] + v[n] << endl;
        m++; // ��ʼ�±���ǰ��һλ
        n--; // ĩβ�±����һλ
    }

    return 0;
}
