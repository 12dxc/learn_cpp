#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
    // �Ƚ������ַ���
    // string
    string s1("hello");
    string s2("hello");
    if (s1 == s2)
    {
        cout << "�����ַ������" << endl;
    }
    else
    {
        cout << "�����ַ��������" << endl;
    }

    // C style string
    char a1[] = "hello";
    char a2[] = "hello";
    if (strcmp(a1, a2) == 0)
    {
        cout << "�����ַ������" << endl;
    }
    else
    {
        cout << "�����ַ��������" << endl;
    }

    return 0;
}
