#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
     unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, spaceCnt = 0, tabCnt = 0, newLineCnt = 0;
     ;
     char c;
     // noskipws �������հ׷���
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
          }
     }
     cout << "Ԫ��a���ֵĴ���: \t" << aCnt << '\n'
          << "Ԫ��e���ֵĴ���: \t" << eCnt << '\n'
          << "Ԫ��i���ֵĴ���: \t" << iCnt << '\n'
          << "Ԫ��o���ֵĴ���: \t" << oCnt << '\n'
          << "Ԫ��u���ֵĴ���: \t" << uCnt << '\n'
          << "�ո���ֵĴ���: \t" << spaceCnt << '\n'
          << "�Ʊ�����ֵĴ���: \t" << tabCnt << '\n'
          << "���з����ֵĴ���: \t" << newLineCnt << endl;

     system("pause");
     return 0;
}
