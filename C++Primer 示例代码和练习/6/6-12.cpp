#include <iostream>
using namespace std;

// �鿴�Ƿ��д�д��ĸ
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
// ��ΪСд
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