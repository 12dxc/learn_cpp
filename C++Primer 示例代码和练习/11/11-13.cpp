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
        // ������������pair
        v.push_back(make_pair(str, n));
        // ���캯����ʼ��
        v.push_back(pair<string, int>(str, n));
        // �б��ʼ��
        v.push_back({str, n});
    }

    for (const auto &i : v)
    {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}