#include <iostream>
#include <vector>
using namespace std;

vector<int> other_vec{1, 2, 3, 4, 5, 6, 7};

// vector ��6�ִ����ͳ�ʼ����ʽ
int main()
{
    // Ĭ��
    vector<int> v1; // 0
    // ָ������
    vector<int> v3(10); // 0
    // ��ʾָ��ֵ ��ʼ��
    vector<int> v2{1, 2, 3, 4, 5}; // 1,2,3,4,5
    // ����������Ԫ�أ���n����ͬԪ��
    vector<int> v4(10, 1); // 1
    // ����
    vector<int> v5(other_vec); // 1, 2, 3, 4, 5, 6, 7
    // ��Χ����
    vector<int> v6(other_vec.begin(), other_vec.begin() + 5); // 1, 2, 3, 4, 5

    return 0;
}