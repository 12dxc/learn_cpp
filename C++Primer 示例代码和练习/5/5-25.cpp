#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
     int i, j;
     cout << "������������: " << endl;
     while (cin >> i >> j)
     {
          try
          {
               if (j == 0)
                    throw runtime_error("��������Ϊ0");
               cout << i / j << endl;
          }
          catch (runtime_error err)
          {
               cout << err.what() << "\nҪ����һ����yes or no" << endl;
               char c;
               cin >> c;
               if (c != 'y')
                    break;
          }
          cout << "������������: " << endl;
     }

     system("pause");
     return 0;
}
