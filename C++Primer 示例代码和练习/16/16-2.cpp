#include <iostream>
#include <string>

template <typename T>
int compare(const T &lhs, const T &rhs)
{
    if (lhs > rhs)
        return 1;
    if (rhs > lhs)
        return -1;
    return 0;s
}

int main()
{

    return 0;
}
