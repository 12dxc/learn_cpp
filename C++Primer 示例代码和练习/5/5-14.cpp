#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 输入若干string对象，记录连续重复出现的最大次数以及单词
int main()
{
     // 使用一个对组来存取字符串，及其出现的次数
     pair<string, int> max_duplicated;
     // 设置一个计数器，用于存储出现的次数
     int count = 0;

     string str, prestr;
     while (cin >> str)
     {
          // 如果与上一个字符串相等，计数器加1
          if (prestr == str)
          {
               count++;
          }
          // 如果遇上不同的字符，连续中断，重置计数器
          else
          {
               count = 0;
          }
          // 当计数器大于对组的存储的数字时，说明已有连续出现的单词
          // 将连续出现的单词和次数赋给对组
          if (count > max_duplicated.second)
               max_duplicated = {prestr, count};
          prestr = str;
     }
     if (max_duplicated.first.empty())
     {
          cout << "没有单词连续出现过" << endl;
     }
     else
     {
          cout << max_duplicated.first << " 出现了" << max_duplicated.second + 1 << "次" << endl;
     }

     system("pause");
     return 0;
}
