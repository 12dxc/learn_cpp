#include <iostream>
#include <forward_list>
using namespace std;

int main()
{
    forward_list<int> flst{1, 2, 3, 4, 5, 6, 7};
    auto prev = flst.before_begin(); // 表示flst的首前元素
    auto curr = flst.begin();        // 表示flst的第一个元素
    while (curr != flst.end())
    {
        if (*curr % 2)
        {
            curr = flst.erase_after(prev);
        }
        else
        {
            prev = curr; // prev指向上一个元素
            ++curr;      // 移动迭代器指向下一个元素}
        }
    }
    for (auto i : flst)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}