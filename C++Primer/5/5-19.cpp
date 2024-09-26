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

          cout << "请输入两个字符串:" << endl;
          cin >> str1 >> str2;
          if (str1.size() > str2.size())
               cout << str1 << endl;
          else
               cout << str2 << endl;

          cout << "请问是否还要继续输出 yes or no" << endl;
          cin >> rsp;

     } while (rsp[0] == 'y');

     system("pause");
     return 0;
}
