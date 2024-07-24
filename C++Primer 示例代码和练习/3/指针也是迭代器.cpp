#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // 指针也可做迭代器
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //C++11新引入的begin函数和end函数，功能与迭代器类型
    auto b = begin(arr), e = end(arr);
    for (auto b = begin(arr); b != end(arr) && *b >= 0; b++)
    {
        cout << *b << " ";
    }

    return 0;
}
