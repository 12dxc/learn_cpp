#include <iostream>
#include <vector>
using namespace std;

// 比较两个数组是否相等
bool compare(int *pb1, int *pe1, int *pb2, int *pe2)
{
    // 先比较长度，如果相等再依次比较每个元素
    if ((pe1 - pb1) != (pe2 - pb2))
    {
        return false;
    }
    else
    {
        for (auto i = pb1, j = pb1; (i != pe1) && (j != pe2); i++, j++)
        {
            if (*i != *j)
                return false;
        }
        return true;
    }
}

int main()
{

    // array
    int arr1[] = {1, 2, 3};
    int arr2[] = {1, 2, 3};

    if (compare(begin(arr1), end(arr1), begin(arr2), end(arr2)))
    {
        cout << "数组相等" << endl;
    }
    else
    {
        cout << "数组不相等" << endl;
    }

    cout << "===========================" << endl;

    // 对比两个向量
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {1, 2, 3};
    if (v1 == v2)
    {
        cout << "数组相等" << endl;
    }
    else
    {
        cout << "数组不相等" << endl;
    }

    return 0;
}
