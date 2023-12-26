#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool predicate(const string &s)
{
    return s.size() <= 5;
}

int main()
{
    auto v = vector<string>{"a", "as", "aasss", "aaaaassaa", "aaaaaabba", "aaa"};
    // ���������ݽ��л��֣�����ν�ʵķ�ǰ�棬����ź���
    auto newEnd = partition(v.begin(), v.end(), predicate);

    for (auto it = v.begin(); it != newEnd; it++)
        cout << *it << " ";
    cout << endl;

    return 0;
}