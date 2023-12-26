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
        v.push_back(make_pair(str, n));
    }

    for (const auto &i : v)
    {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}