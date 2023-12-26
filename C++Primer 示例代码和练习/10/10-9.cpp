#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

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
    sort(v.begin(), v.end());
    println(v);

    // 使得只出现依次的单词排列在前部，并返回指向不重复区域之后的一个迭代器
    auto end_unique = unique(v.begin(), v.end());
    println(v);

    v.erase(end_unique, v.end());
    return v;
}

int main()
{
    vector<string> vs{"a", "v", "a", "s", "v", "a", "a"};
    println(vs);
    println(elimDups(vs));
    return 0;
}