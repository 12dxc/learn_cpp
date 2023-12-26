#include <iostream>
using namespace std;

// ÇóÊý½×³Ë
int fact(int i)
{

     return i > 1 ? i * fact(i - 1) : 1;
}
int main()
{
     cout << "5! is " << fact(5) << endl;

     system("pause");
     return 0;
}
