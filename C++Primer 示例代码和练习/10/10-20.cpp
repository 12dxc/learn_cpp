#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

auto bigerThan6(vector<string> const &v)
{
    return count_if(v.begin(), v.end(), [](string const &s)
                    { return s.size() > 6; });
}

int main()
{
    vector<string> v{"1234", "123456", "1234567", "1234567", "1234567", "1234567"};
    cout << bigerThan6(v);

    return 0;
}