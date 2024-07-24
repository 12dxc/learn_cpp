#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 二元谓词，此用作指定sort排序规则
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() > s2.size();
}

template <typename T>
auto println(T const &elem) -> ostream &
{
    for (auto const &i : elem)
    {
        cout << i << " ";
    }
    return cout << endl;
}

auto elimDups(vector<string> &v) -> vector<string> &
{
    sort(v.begin(), v.end(), isShorter);
    println(v);

    // 使得只出现依次的单词排列在前部，并返回指向不重复区域之后的一个迭代器
    auto end_unique = unique(v.begin(), v.end());
    println(v);

    v.erase(end_unique, v.end());
    return v;
}

int main()
{
    vector<string> v{
        "1234", "1234", "1234", "Hi", "alan", "wang"};
    elimDups(v);
    // 按字典序，但有长度排序谓词
    stable_sort(v.begin(), v.end(), isShorter);
    cout << "ex10.11 :\n";
    println(v);

    return 0;
}