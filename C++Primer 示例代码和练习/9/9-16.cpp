#include <iostream>
#include <vector>
#include <list>
using namespace std;

// �ж����������Ƿ����
int main()
{
    vector<int> v{1, 2, 3};
    list<int> l{1, 2, 3, 4};

    // ��ͬ����֮��Ƚϣ�ֻ�ܽ������е�Ԫ�ؿ�����һ����֮��ͬ����������
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