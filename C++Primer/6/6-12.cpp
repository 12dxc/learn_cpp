#include <iostream>
using namespace std;

// 查看是否有大写字母
bool any_capital(const string &str)
{

     for (auto c : str)
     {
          if (isupper(c))
               return true;
          else
               return false;
     }
}
// 改为小写
void to_lowercase(string &str)
{
     for (auto &c : str)
     {
          c = toupper(c);
     }
}

int main()
{
     string hello("Hello World!");
     cout << any_capital(hello) << endl;

     to_lowercase(hello);
     cout << hello << endl;

     return 0;
}