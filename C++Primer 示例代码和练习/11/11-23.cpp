#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main()
{
    multimap<string, vector<string>> m;
    for (string ln; cout << "��:\n", cin >> ln && ln != "@q";)
        for (string cn; cout << "�����ǵ���:\n", cin >> cn && cn != "@q";)
            m.emplace(ln, cn);

    return 0;
}