#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // ��cin����һ���ַ����������Ǵ浽һ��vector������
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
