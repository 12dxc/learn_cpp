#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
    list<const char *> l{"hello", "world"};
    vector<string> v;
    // const char* ���ó���������
    v.assign(l.cbegin(), l.cend());
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}