#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
     // ���������������ֱ��ʾ��ǰ�ַ�������һ���ַ���
     string str, prvStr = "\0";
     while (cin >> str)
     {
          if (isupper(str[0]) && str == prvStr)
          {
               cout << str << " :��������������" << endl;
               break;
          }
          prvStr = str;
     }
     cout << "û���ظ����ֵĵ���" << endl;

     system("pause");
     return 0;
}
