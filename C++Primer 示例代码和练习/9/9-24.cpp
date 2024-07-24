#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    // 因为是空容器，使用at会抛出一个out_of_range异常
    cout << v.at(0);
    cout << v[0];
    cout << v.front();
    cout << *v.begin();

    return 0;
}