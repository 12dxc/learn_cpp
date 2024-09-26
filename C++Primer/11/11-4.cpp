#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main()
{
    map<string, size_t> word_count;

    string word;
    while (cin >> word)
    {
        for (auto &i : word)
        {
            i = tolower(i);
        }
        word.erase(remove_if(word.begin(), word.end(), [](char c)
                             { return ispunct(c); }),
                   word.end());
        ++word_count[word];
    }

    for (const auto &i : word_count)
    {
        cout << i.first << " : " << i.second << endl;
    }

    return 0;
}