#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
     unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, spaceCnt = 0, tabCnt = 0, newLineCnt = 0, ffCnt = 0, flCnt = 0, fiCnt = 0;
     // prech ���ڱ���ǰһ���ַ�
     char c, prech = '\0';
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
          // ����ǰ�ַ������洢��һ���ַ��ı���������֮�����ж�
          prech = c;
     }
     cout << "Ԫ��a���ֵĴ���: \t" << aCnt << '\n'
          << "Ԫ��e���ֵĴ���: \t" << eCnt << '\n'
          << "Ԫ��i���ֵĴ���: \t" << iCnt << '\n'
          << "Ԫ��o���ֵĴ���: \t" << oCnt << '\n'
          << "Ԫ��u���ֵĴ���: \t" << uCnt << '\n'
          << "�ո���ֵĴ���: \t" << spaceCnt << '\n'
          << "�Ʊ�����ֵĴ���: \t" << tabCnt << '\n'
          << "���з����ֵĴ���: \t" << newLineCnt << '\n'
          << "ff ���ֵĴ���: \t" << ffCnt << '\n'
          << "fl ���ֵĴ���: \t" << flCnt << '\n'
          << "fi ���ֵĴ���: \t" << fiCnt << endl;

     system("pause");
     return 0;
}
