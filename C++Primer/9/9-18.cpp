#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
    deque<string> input;
    for (string s; cin >> s; input.push_back(s))
        ;
    for (auto it = input.cbegin(); it != input.cend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}