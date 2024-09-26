#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<string, vector<string>> name;
    for (string ln; cout << "Last name:\n", cin >> ln && ln != "@q";)
        for (string cn; cout << "|-Children's names:\n", cin >> cn && cn != "@q";)
            name[ln].push_back(cn);

    return 0;
}