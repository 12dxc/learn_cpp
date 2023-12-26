#include <iostream>
using namespace std;

int main()
{
    int sum = 0, val = 10;
    while (val != 0)
    {
        sum += val;
        --val;
    }
    cout << "10~0µÄºÍÎª:" << sum;

    return 0;
}
