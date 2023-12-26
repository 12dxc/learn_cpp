#include <iostream>
using namespace std;

int main()
{
    int sum = 0, val = 50;
    while (val <= 100)
    {
        sum += val;
        ++val;
    }
    cout << "50~100µÄºÍÎª:" << sum;

    return 0;
}
