#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
    // ��ia������list��vector
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    list<int> l(ia, end(ia));
    vector<int> v(l.begin(), l.end());

    // ʹ�õ����������earselistɾ������Ԫ�أ�vectorɾ��ż��Ԫ��
    for (auto it = l.begin(); it != l.end();)
    {
        if (*it % 2 != 0)
        {
            // earse������һ��Ԫ�ص��������൱�ڵ���
            it = l.erase(it);
        }
        else
        {
            // ����������������
            it++;
        }
    }
    for (auto it = v.begin(); it != v.end();)
    {
        if (*it % 2 == 0)
        {
            it = v.erase(it);
        }
        else
        {
            it++;
        }
    }

    for (auto i : l)
        cout << i
             << " ";
    cout << endl;
    for (auto i : v)
        cout << i
             << " ";
    cout << endl;

    return 0;
}