#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // ��vector��Ԫ�ؿ�����������
    vector<int> v = {1, 2, 3, 4, 5, 6};
    int arr[v.size()];
    for (int i = 0; i != v.size(); i++)
    {
        arr[i] = v[i];
    }

    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
