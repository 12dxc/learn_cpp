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
        ++word_count[word];
    }

    for (const auto &i : word_count)
    {
        cout << i.first << " : " << i.second << endl;
    }

    return 0;
}