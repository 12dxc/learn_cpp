#include <iostream>
#include <list>
#include <deque>
using namespace std;

int main()
{
    list<int> l{1, 2, 3, 4, 5, 6, 7};
    deque<int> odd, even;

    for (auto i : l)
    {
        if (i % 2)
        {
            even.push_back(i);
        }
        else
        {
            odd.push_back(i);
        }
    }

    for (auto i : odd)
        cout << i << " ";
    cout << endl;
    for (auto i : even)
        cout << i << " ";
    cout << endl;

    return 0;
}