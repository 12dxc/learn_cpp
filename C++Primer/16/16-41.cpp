#include <iostream>
using namespace std;

template <typename T>
auto sum(const T &lhs, const T &rhs) -> decltype(lhs + rhs)
{
    return lhs + rhs;
}

main()
{

    return 0;
}
