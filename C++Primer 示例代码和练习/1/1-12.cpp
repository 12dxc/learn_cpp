#include <iostream>
using namespace std;

// ʹ��forѭ����д1.4.1��ϰ

int main()
{
    // 1.9
    int sum = 0;
    for (int i = 50; i <= 100; i++)
    {
        sum += i;
    }
    cout << "50~100�ĺ�Ϊ:" << sum << endl;

    // 1.10
    sum = 0;
    for (int i = 10; i != 0; i--)
    {
        sum += i;
    }
    cout << "10~0�ĺ�Ϊ:" << sum << endl;

    // 1.11
    sum = 0;
    int lnum = 0, rnum = 0;
    cout << "������������:" << endl;
    cin >> lnum >> rnum;
    cout << lnum << "~" << rnum << "��Χ�ڵ�����:" << endl;
    for (int i = lnum; i <= rnum; i++)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
