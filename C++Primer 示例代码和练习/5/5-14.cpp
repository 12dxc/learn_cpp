#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ��������string���󣬼�¼�����ظ����ֵ��������Լ�����
int main()
{
     // ʹ��һ����������ȡ�ַ�����������ֵĴ���
     pair<string, int> max_duplicated;
     // ����һ�������������ڴ洢���ֵĴ���
     int count = 0;

     string str, prestr;
     while (cin >> str)
     {
          // �������һ���ַ�����ȣ���������1
          if (prestr == str)
          {
               count++;
          }
          // ������ϲ�ͬ���ַ��������жϣ����ü�����
          else
          {
               count = 0;
          }
          // �����������ڶ���Ĵ洢������ʱ��˵�������������ֵĵ���
          // ���������ֵĵ��ʺʹ�����������
          if (count > max_duplicated.second)
               max_duplicated = {prestr, count};
          prestr = str;
     }
     if (max_duplicated.first.empty())
     {
          cout << "û�е����������ֹ�" << endl;
     }
     else
     {
          cout << max_duplicated.first << " ������" << max_duplicated.second + 1 << "��" << endl;
     }

     system("pause");
     return 0;
}
