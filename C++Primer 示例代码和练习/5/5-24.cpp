#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
     int num1, num2;
     cin >> num1 >> num2;
     if (num2 == 0)
     {
          throw runtime_error("除数不能为0");
     }
     cout << num1 / num2 << endl;

     system("pause");
     return 0;
}
