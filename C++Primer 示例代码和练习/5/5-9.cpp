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
     cout << "元音a出现的次数: \t" << aCnt << '\n'
          << "元音e出现的次数: \t" << eCnt << '\n'
          << "元音i出现的次数: \t" << iCnt << '\n'
          << "元音o出现的次数: \t" << oCnt << '\n'
          << "元音u出现的次数: \t" << uCnt << endl;

     system("pause");
     return 0;
}
