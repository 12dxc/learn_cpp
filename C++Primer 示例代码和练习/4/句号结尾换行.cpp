#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<string> vStr = {"hello", "world.", "HI"};
    // string������ܷǳ������Խ�s����Ϊ�������Ϳ��Ա����Ԫ�صĿ�����
    // ������Ϊ����string��������д����������s������Ϊ��������
    for (const auto &s : vStr)
    {
        cout << s;
        if (s.empty() || s[s.size() - 1] == '.')
        {
            cout << endl;
        }
        else
        {
            cout << " ";
        }
    }

    return 0;
}
