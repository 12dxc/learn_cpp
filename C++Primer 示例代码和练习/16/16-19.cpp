#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void print(const T &v)
{
    for (typename T::size_type i = 0; i != v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    print(v);

    return 0;
}
