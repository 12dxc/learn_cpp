#include <iostream>
#include <memory>
#include <cstring>
#include <string>
using namespace std;

int main()
{
    cout << "��������һ�������ַ���?" << endl;
    int size = 0;
    cin >> size;
    char *input = new char[size + 1]();
    // ������뻺����    ��Ϊ��һ�����������ɻ���������
    cin.ignore();
    cout << "�������ַ���: ";
    // get ��������ʽ�����ڶ�ȡһ�� ��һ��ΪҪ������ַ� n��ʾĿ��ռ�Ĵ�С��
    cin.get(input, size + 1);
    cout << input;
    // �ͷŶ�̬����
    delete[] input;

    return 0;
}