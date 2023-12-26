#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str("this is a string");

    // while循环形式
    int i = 0;
    while (i < str.size())
    {
        str[i] = 'X';
        i++;
    }
    cout << "while循环实现: " << str << endl;

    // for循环形式
    for (int i = 0; i < str.size(); i++)
    {
        str[i] = 'X';
    }
    cout << "for循环实现: " << str << endl;

    return 0;
}
