#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 9};
    fill_n(v.begin(), v.size(), 0);
    for (auto const &i : v)
        cout << i << " ";
    cout << endl;
    return 0;
}