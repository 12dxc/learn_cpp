#include <iostream>
#include <forward_list>
#include <string>
using namespace std;

auto find_and_insert(forward_list<string> &flst, const string &s1, const string &s2)
{
    auto prev = flst.before_begin();
    auto curr = flst.begin();
    while (curr != flst.end())
    {
        if (*curr == s1)
        {
            flst.insert_after(flst.end(), s2);
            return;
        }
        prev = curr;
        ++curr;
    }
    flst.insert_after(prev, s2);
}

int main()
{

    return 0;
}