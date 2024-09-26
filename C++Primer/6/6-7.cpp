#include <iostream>
using namespace std;

int test()
{
     static int i;
     return i++;
}
int main()
{
     for (int i = 0; i != 10; ++i)
          cout << test() << endl;

     return 0;
}