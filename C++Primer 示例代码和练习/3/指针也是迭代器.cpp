#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // ָ��Ҳ����������
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //C++11�������begin������end���������������������
    auto b = begin(arr), e = end(arr);
    for (auto b = begin(arr); b != end(arr) && *b >= 0; b++)
    {
        cout << *b << " ";
    }

    return 0;
}
