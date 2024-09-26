#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int i = 10;
    auto f = [&i]() -> bool
    { return (i == 0 ? true : !(i--)); };
    while (!f())
        cout << i << endl;

    return 0;
}