#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main()
{
    multimap<string, vector<string>> m;
    for (string ln; cout << "姓:\n", cin >> ln && ln != "@q";)
        for (string cn; cout << "孩子们的名:\n", cin >> cn && cn != "@q";)
            m.emplace(ln, cn);

    return 0;
}