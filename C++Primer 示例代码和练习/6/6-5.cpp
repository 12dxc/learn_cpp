#include <iostream>
using namespace std;

// �����׳�
int absolute_value(int i)
{

     return i > 0 ? i : -i; // �����ټ�һ�����ż���תΪ����
}
int main()
{
     cout << "������һ������:" << endl;
     int n;
     cin >> n;
     cout << n << " �ľ���ֵ: " << absolute_value(n) << endl;

     system("pause");
     return 0;
}
