#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str("this is a string");

    // whileѭ����ʽ
    int i = 0;
    while (i < str.size())
    {
        str[i] = 'X';
        i++;
    }
    cout << "whileѭ��ʵ��: " << str << endl;

    // forѭ����ʽ
    for (int i = 0; i < str.size(); i++)
    {
        str[i] = 'X';
    }
    cout << "forѭ��ʵ��: " << str << endl;

    return 0;
}
