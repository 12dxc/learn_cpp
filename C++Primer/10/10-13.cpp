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
    // 对容器内容进行划分，符合谓词的放前面，否则放后面
    auto newEnd = partition(v.begin(), v.end(), predicate);

    for (auto it = v.begin(); it != newEnd; it++)
        cout << *it << " ";
    cout << endl;

    return 0;
}