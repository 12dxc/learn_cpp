#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // array
    int arr[10];
    for (int i = 0; i < 10; i++)
        arr[i] = i;
    // 将上个数组拷贝到另一个数组
    int arr2[10];
    for (int i = 0; i < 10; i++)
        arr2[i] = arr[i];

    // vector
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
