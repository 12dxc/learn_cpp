#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    // ����һ������10��42��vector����
    // 1���б��ʼ��
    vector<int> v = {42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
    // 2�����캯����ʼ��
    vector<int> v2(10, 42);
    // 3��forѭ��׷��Ԫ��
    vector<int> v3;
    for (int i = 0; i < 10; i++)
        v3.push_back(42);

    // ���еڶ��ַ������ţ���������С

    return 0;
}
