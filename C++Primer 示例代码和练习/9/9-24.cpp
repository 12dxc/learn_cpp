#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    // ���ǿ�������ʹ��at���׳�һ��out_of_range�쳣
    cout << v.at(0);
    cout << v[0];
    cout << v.front();
    cout << *v.begin();

    return 0;
}