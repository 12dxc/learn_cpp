#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
     unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, spaceCnt = 0, tabCnt = 0, newLineCnt = 0, ffCnt = 0, flCnt = 0, fiCnt = 0;
     // prech 用于保存前一个字符
     char c, prech = '\0';
     // noskipws 不跳过空白符；
     while (cin >> noskipws >> c)
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
               if (prech == 'f')
                    ++fiCnt;
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
          case ' ':
               ++spaceCnt;
               break;
          case '\t':
               ++tabCnt;
               break;
          case '\n':
               ++newLineCnt;
               break;
          case 'f':
               if (prech == 'f')
                    ++ffCnt;
               break;
          case 'l':
               if (prech == 'f')
                    ++flCnt;
               break;
          }
          // 将当前字符赋给存储上一个字符的变量，以在之后做判断
          prech = c;
     }
     cout << "元音a出现的次数: \t" << aCnt << '\n'
          << "元音e出现的次数: \t" << eCnt << '\n'
          << "元音i出现的次数: \t" << iCnt << '\n'
          << "元音o出现的次数: \t" << oCnt << '\n'
          << "元音u出现的次数: \t" << uCnt << '\n'
          << "空格出现的次数: \t" << spaceCnt << '\n'
          << "制表符出现的次数: \t" << tabCnt << '\n'
          << "换行符出现的次数: \t" << newLineCnt << '\n'
          << "ff 出现的次数: \t" << ffCnt << '\n'
          << "fl 出现的次数: \t" << flCnt << '\n'
          << "fi 出现的次数: \t" << fiCnt << endl;

     system("pause");
     return 0;
}
