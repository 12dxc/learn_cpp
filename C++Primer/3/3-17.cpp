#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string s;
    vector<string> v;
    while (cin >> s)
    {
        v.push_back(s);
    }
    for (auto i : v)
    {
        for (auto &c : i)
        {
            c = toupper(c);
        }
        cout << i << endl;
    }

    return 0;
}
