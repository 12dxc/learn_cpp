#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
     // 声明两个变量，分别表示当前字符串和上一个字符串
     string str, prvStr = "\0";
     while (cin >> str)
     {
          if (isupper(str[0]) && str == prvStr)
          {
               cout << str << " :连续出现了两次" << endl;
               break;
          }
          prvStr = str;
     }
     cout << "没有重复出现的单词" << endl;

     system("pause");
     return 0;
}
