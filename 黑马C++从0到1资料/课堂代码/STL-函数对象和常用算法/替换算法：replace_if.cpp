#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// ���ÿ������滻�㷨 replace_if  ������������������Ԫ�أ��滻��ָ��Ԫ��
void myPrint(int val)
{
    cout << val << " ";
}
class Greater30
{
public:
    bool operator()(int v)
    {
        return v >= 30;
    }
};
void test01()
{
    vector<int> v;
    v.push_back(20);
    v.push_back(30);
    v.push_back(20);
    v.push_back(40);
    v.push_back(50);
    v.push_back(10);
    v.push_back(20);

    cout << "�滻ǰ��" << endl;
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;

    // �����ڵ���30���滻Ϊ3000
    replace_if(v.begin(), v.end(), Greater30(), 3000);

    cout << "�滻��" << endl;
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
}

int main()
{

    test01();

    system("pause");
    return 0;
}