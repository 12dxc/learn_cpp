#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 6, 6, 2};
    cout << "6出现的次数: " << count(v.begin(), v.end(), 6) << endl;

    return 0;
}