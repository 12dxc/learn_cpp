#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void print(const T &v)
{
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    print(v);

    return 0;
}
