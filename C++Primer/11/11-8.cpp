#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    vector<string> exclude = {"aa", "bb", "cc", "dd", "ee", "ff"};
    for (string word; cout << "Enter plz:\n", cin >> word;)
    {
        auto is_excluded = binary_search(exclude.cbegin(), exclude.cend(), word);
        auto reply = is_excluded ? "excluded" : "not excluded";
        cout << reply << endl;
    }

    return 0;
}