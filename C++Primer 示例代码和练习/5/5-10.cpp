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
     cout << "元音a出现的次数: \t" << aCnt << '\n'
          << "元音e出现的次数: \t" << eCnt << '\n'
          << "元音i出现的次数: \t" << iCnt << '\n'
          << "元音o出现的次数: \t" << oCnt << '\n'
          << "元音u出现的次数: \t" << uCnt << endl;

     system("pause");
     return 0;
}
