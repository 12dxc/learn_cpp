#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
    vector<int> v{1, 2, 3, 4, 5};
    cout << accumulate(v.begin(), v.end(), 0);

    return 0;
}