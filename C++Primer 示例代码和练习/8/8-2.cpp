#include <iostream>
using namespace std;

istream &func(istream &is)
{
     string s;
     while (is >> s)
     {
          cout << s << endl;
     }
     // ������λ
     is.clear();
     return is;
}

int main()
{
     istream &is = func(cin);
     // ����������״̬
     cout << is.rdstate() << endl;
     return 0;
}