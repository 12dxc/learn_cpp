#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // ����ָ�뽫�����е�Ԫ����Ϊ0
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto p = arr;
    for (int i = 0; i < 10; i++)
    {
        *(p + i) = 0;
    }

    // ��ӡ������
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
