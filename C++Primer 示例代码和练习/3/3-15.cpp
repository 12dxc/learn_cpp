#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // 用cin读入一组字符串并把它们存到一个vector对象中
    string s;
    vector<string> v;
    while (cin >> s)
    {
        v.push_back(s);
    }

    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
