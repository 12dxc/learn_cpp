#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
     string rsp;
     do
     {
          string str1, str2;

          cout << "�����������ַ���:" << endl;
          cin >> str1 >> str2;
          if (str1.size() > str2.size())
               cout << str1 << endl;
          else
               cout << str2 << endl;

          cout << "�����Ƿ�Ҫ������� yes or no" << endl;
          cin >> rsp;

     } while (rsp[0] == 'y');

     system("pause");
     return 0;
}
