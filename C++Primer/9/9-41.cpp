#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<char> vStr{'h', 'e', 'l', 'l', 'o'};
    string str(vStr.begin(), vStr.end());
    for (auto c : str)
    {
        cout << c;
    }

    return 0;
}