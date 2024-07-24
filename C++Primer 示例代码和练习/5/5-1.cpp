#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
     int sum = 0, val = 1;
     // 这种写法代码可读性不高
     while (val <= 10)
          sum += val, ++val;

     cout << "Sum of 1 to 10 inclusive is "
          << sum << std::endl;

     system("pause");
     return 0;
}
