#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
     unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
     char c;
     while (cin >> c)
     {
          if (c == 'a')
               ++aCnt;
          else if (c == 'e')
               ++eCnt;
          else if (c == 'i')
               ++iCnt;
          else if (c == 'o')
               ++oCnt;
          else if (c == 'u')
               ++uCnt;
     }
     cout << "Ԫ��a���ֵĴ���: \t" << aCnt << '\n'
          << "Ԫ��e���ֵĴ���: \t" << eCnt << '\n'
          << "Ԫ��i���ֵĴ���: \t" << iCnt << '\n'
          << "Ԫ��o���ֵĴ���: \t" << oCnt << '\n'
          << "Ԫ��u���ֵĴ���: \t" << uCnt << endl;

     system("pause");
     return 0;
}
