#include <iostream>
#include <vector>
#include <list>
using namespace std;

// 判断两个向量是否相等
int main()
{
    vector<int> v{1, 2, 3};
    list<int> l{1, 2, 3, 4};

    // 不同容器之间比较，只能将容器中的元素拷到另一个与之相同的容器类型
    if (v == vector<int>(l.begin(), l.end()))
    {
        cout << "vector == list" << endl;
    }
    else
    {
        cout << "vector != list" << endl;
    }

    return 0;
}