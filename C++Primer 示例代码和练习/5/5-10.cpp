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
          switch (c)
          {
          case 'a':
          case 'A':
               ++aCnt;
               break;
          case 'e':
          case 'E':
               ++eCnt;
               break;
          case 'i':
          case 'I':
               ++iCnt;
               break;
          case 'o':
          case 'O':
               ++oCnt;
               break;
          case 'u':
          case 'U':
               ++uCnt;
               break;
          }
     }
     cout << "Ԫ��a���ֵĴ���: \t" << aCnt << '\n'
          << "Ԫ��e���ֵĴ���: \t" << eCnt << '\n'
          << "Ԫ��i���ֵĴ���: \t" << iCnt << '\n'
          << "Ԫ��o���ֵĴ���: \t" << oCnt << '\n'
          << "Ԫ��u���ֵĴ���: \t" << uCnt << endl;

     system("pause");
     return 0;
}
