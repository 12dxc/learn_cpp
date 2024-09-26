#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void elimDups(vector<string> &vs)
{
    std::sort(vs.begin(), vs.end());
    auto new_end = std::unique(vs.begin(), vs.end());
    vs.erase(new_end, vs.end());
}
void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words); // 将word按字典排序，删除重复单词
    // 按长度排序
    stable_sort(words.begin(), words.end(),
                [](const string &a, const string &b)
                { return a.size() < b.size(); });
    // 获取一个迭代器，指向第一个满足size()>=sz的元素
    auto wc = partition(words.begin(), words.end(),
                        [sz](const string &a)
                        { return a.size() >= sz; });
    // 循环打印
    for_each(words.begin(), wc,
             [](const string &s)
             { std::cout << s << " "; });
}

int main()
{
    vector<string> v{
        "1234", "1234", "1234", "hi~", "alan", "alan", "cp"};
    cout << "大于等于3的非重复字符串: ";
    biggies(v, 3);
    cout << endl;

    return 0;
}