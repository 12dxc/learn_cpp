#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string str;
    int n;
    vector<pair<string, int>> v;

    while (cin >> str >> n)
    {
        // 函数方法返回pair
        v.push_back(make_pair(str, n));
        // 构造函数初始化
        v.push_back(pair<string, int>(str, n));
        // 列表初始化
        v.push_back({str, n});
    }

    for (const auto &i : v)
    {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}