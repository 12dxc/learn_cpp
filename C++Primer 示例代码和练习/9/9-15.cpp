#include <iostream>
#include <vector>
using namespace std;

// 判断两个向量是否相等
int main()
{
    vector<int> v1{1, 2, 3}, v2{1, 2, 3, 4};
    if (v1 == v2)
    {
        cout << "v1 == v2" << endl;
    }
    else
    {
        cout << "v1 != v2" << endl;
    }

    return 0;
}