#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// ���ÿ������滻�㷨 copy ������ָ����Χ��Ԫ�ؿ�������һ������
void myPrint(int val)
{
    cout << val << " ";
}
void test01()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    vector<int> v2;
    v2.resize(v1.size());

    // ��v1������v2
    copy(v1.begin(), v1.end(), v2.begin());
    for_each(v2.begin(), v2.end(), myPrint);
    cout << endl;
}

int main()
{

    test01();

    system("pause");
    return 0;
}