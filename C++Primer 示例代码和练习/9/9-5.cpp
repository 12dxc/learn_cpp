#include <iostream>
#include <vector>
using namespace std;

// ����Ԫ���Ƿ��������в�����
int find(vector<int> &v, int target)
{

    for (auto it = v.begin(); it != v.end(); it++)
    {
        if (*it == target)
        {
            return *it;
        }
    }
    // ����-1δ�ҵ�
    return -1;
}

int main()
{
    vector<int> v = {1, 2, 3, 53, 4, 6, 45, 47, 56, 58, 50};
    cout << find(v, 47) << endl;

    return 0;
}