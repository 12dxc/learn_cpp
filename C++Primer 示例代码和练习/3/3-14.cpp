#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // 用cin读入一组整数并把它们存到一个vector对象中
    int n;
    vector<int> v;
    while (cin >> n)
    {
        v.push_back(n);
    }

    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
