#include <iostream>
using namespace std;

template <typename T, unsigned N>
constexpr unsigned size(const T (&arr)[N])
{
    return N;
}
int main()
{

    return 0;
}
