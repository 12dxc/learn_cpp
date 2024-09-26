#include <iostream>
using namespace std;

void reset(int &i)
{
     i = 0;
}

int main()
{
     int j = 42;
     reset(j);
     cout << j << endl;
     return 0;
}