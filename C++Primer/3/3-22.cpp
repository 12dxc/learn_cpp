#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<string> text{"hello", "world"};
    for (auto it = text.begin(); it != text.end() && !it->empty(); it++)
    {
        for (auto &c : *it)
        {
            if (isalpha(c))
                c = toupper(c);
        }
    }
    for (auto i : text)
    {
        cout << i << endl;
    }

    return 0;
}
