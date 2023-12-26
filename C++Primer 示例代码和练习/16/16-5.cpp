#include <iostream>
using namespace std;

template <typename T>
void print(const T &arr)
{
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
}

int main()
{
    char a1[34] = {'h', 'e', 'l', 'o', 'o'};
    print(a1);
    double a2[10] = {1.2, 2.3, 3.4, 5.6, 9.0, 7.6};
    print(a2);

    return 0;
}
