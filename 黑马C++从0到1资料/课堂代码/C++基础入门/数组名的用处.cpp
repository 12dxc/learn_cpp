#include<iostream>
using namespace std;

int main() {
	//����������;

	int arr[5] = { 1,2,3,4,5 };
	//1. ����ͨ��������ͳ����������ռ���ڴ��С
	cout << "��������ռ�õ��ڴ�ռ�Ϊ��" << sizeof(arr) << endl;
	cout << "ÿ��Ԫ��ռ���ڴ�ռ�Ϊ��" << sizeof(arr[0]) << endl;
	cout << "������Ԫ�ظ���" << sizeof(arr) / sizeof(arr[0]) << endl;
	//2. ����ͨ���������鿴�����׵�ַ
	cout << "�����׵�ַΪ��" << arr << endl;
	system("pause");

	return 0;
}