#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<string, size_t> word_count;

    string word;
    while (cin >> word)
    {
        auto ret = word_count.insert({word, 1});
        if (!ret.second)
            ++ret.first->second;
    }

    for (const auto &i : word_count)
    {
        cout << i.first << " : " << i.second << endl;
    }

    return 0;
}