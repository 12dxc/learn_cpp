#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
     int i, j;
     cout << "请输入两个数: " << endl;
     while (cin >> i >> j)
     {
          try
          {
               if (j == 0)
                    throw runtime_error("除数不能为0");
               cout << i / j << endl;
          }
          catch (runtime_error err)
          {
               cout << err.what() << "\n要再试一次吗，yes or no" << endl;
               char c;
               cin >> c;
               if (c != 'y')
                    break;
          }
          cout << "请输入两个数: " << endl;
     }

     system("pause");
     return 0;
}
