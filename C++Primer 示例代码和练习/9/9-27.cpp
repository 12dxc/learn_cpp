#include <iostream>
#include <forward_list>
using namespace std;

int main()
{
    forward_list<int> flst{1, 2, 3, 4, 5, 6, 7};
    auto prev = flst.before_begin(); // ��ʾflst����ǰԪ��
    auto curr = flst.begin();        // ��ʾflst�ĵ�һ��Ԫ��
    while (curr != flst.end())
    {
        if (*curr % 2)
        {
            curr = flst.erase_after(prev);
        }
        else
        {
            prev = curr; // prevָ����һ��Ԫ��
            ++curr;      // �ƶ�������ָ����һ��Ԫ��}
        }
    }
    for (auto i : flst)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}