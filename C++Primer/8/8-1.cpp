#include <iostream>
using namespace std;

istream &func(istream &is)
{
     string s;
     while (is >> s)
     {
          cout << s << endl;
     }
     // 对流复位
     is.clear();
     return is;
}

int main()
{

     return 0;
}