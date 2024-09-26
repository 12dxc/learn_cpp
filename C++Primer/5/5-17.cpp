#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool is_prefix(vector<int> &v1, vector<int> &v2)
{
     if (v1.size() > v2.size())
     {
          for (int i = 0; i < v2.size(); ++i)
          {
               if (v1[i] != v2[i])
               {
                    return false;
               }
          }
          return true;
     }
     else
     {
          // 如果v2比v1大，直接使用换参继续调用本函数
          is_prefix(v2, v1);
     }
}

int main()
{
     vector<int> v1 = {0, 1, 1, 2};
     vector<int> v2 = {0, 1, 1, 2, 3, 5, 8};

     cout << is_prefix(v1, v2) << endl;

     system("pause");
     return 0;
}
