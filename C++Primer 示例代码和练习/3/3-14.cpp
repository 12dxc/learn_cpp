#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // ��cin����һ�������������Ǵ浽һ��vector������
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
