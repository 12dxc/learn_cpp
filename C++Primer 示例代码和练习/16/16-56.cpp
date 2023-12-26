#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template <typename T>
string debug_rep(const T &t)
{
    ostringstream ret;
    ret << t;
    return ret.str();
}

template <typename T>
string debug_rep(T *p)
{
    ostringstream ret;
    ret << "pointer: " << p;

    if (p)
        ret << " " << debug_rep(*p);
    else
        ret << " null pointer";

    return ret.str();
}

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

template <typename... Args>
ostream &errorMsg(ostream &os, const Args &...rest)
{
    return print(os, debug_rep(rest)...);
}

int main()
{
    int *p = 0;
    errorMsg(cout, 'h', 10, 3.14, p);
    cout << endl;

    system("pause");
    return 0;
}