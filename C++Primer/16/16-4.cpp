#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;

template <typename Iterator, typename Value>
Iterator find(Iterator frist, Iterator last, const Value &v)
{
    for (; frist != last && *frist != v; ++frist)
        ;
    return frist;
}

int main()
{
    vector<int> v{1, 2, 3, 4, 5, 6};
    cout << *(find(v.begin(), v.end(), 4)) << endl;

    list<int> l{1, 2, 3, 4, 5, 6};
    cout << *(find(l.begin(), l.end(), 3)) << endl;

    return 0;
}
