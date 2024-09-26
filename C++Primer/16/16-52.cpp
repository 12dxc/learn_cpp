#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template <typename T, typename... Args>
void foo(const T &t, const Args &...rest)
{
    cout << sizeof...(Args) << endl;
    cout << sizeof...(rest) << endl;
}

int main()
{
    int i = 0;
    double d = 3.14;
    string s = "how now brown cow";
    foo(i, s, 42, d);
    foo(s, 42, d);
    foo(42, d);
    foo(d);

    system("pause");
    return 0;
}