#include <iostream>
using namespace std;

// �����׳�
int fact(int i)
{

     return i > 1 ? i * fact(i - 1) : 1;
}
int main()
{
     cout << "������һ������:" << endl;
     int n;
     cin >> n;
     cout << n << " �Ľ׳�Ϊ: " << fact(n) << endl;

     system("pause");
     return 0;
}
