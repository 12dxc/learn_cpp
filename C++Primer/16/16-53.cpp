#include <iostream>
using namespace std;

template <typename T>
ostream &print(ostream &os, const T &t)
{
    return os << t;
}
template <typename T, typename... Args>
ostream &print(ostream &os, const T &t, const Args... rest)
{
    os << t << ", ";
    return print(os, rest...);
}

int main()
{
    print(cout, 10);
    cout << endl;
    print(cout, 10, 0.14);
    cout << endl;
    print(cout, 10, 0.14, "hello", 'w', true);
    cout << endl;

    system("pause");
    return 0;
}