#include <iostream>
using namespace std;
#include <vector>
#include <numeric>
#include <algorithm>

class myPrint
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};

// �������������㷨  fill  ��䣺�����������ָ����Ԫ��
void test01()
{
    vector<int> v;
    v.resize(10);

    // �����������
    fill(v.begin(), v.end(), 1000);

    for_each(v.begin(), v.end(), myPrint());
    cout << endl;
}

int main()
{

    test01();

    system("pause");
    return 0;
}