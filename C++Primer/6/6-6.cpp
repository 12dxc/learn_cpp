#include <iostream>
using namespace std;

// ����
int count_add(int n) // n���β�
{
     static int ctr = 0; // ctr �Ǿֲ���̬����
     ctr += n;
     return ctr;
}

int main()
{
     for (int i = 0; i != 10; ++i) // i �Ǿֲ�����
          cout << count_add(i) << endl;

     return 0;
}