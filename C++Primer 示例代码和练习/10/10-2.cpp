#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
    list<string> lStr{"hello", "world", "hello", "hello", "hi"};
    cout << "hello ���ֵĴ���: " << count(lStr.begin(), lStr.end(), "hello");

    return 0;
}