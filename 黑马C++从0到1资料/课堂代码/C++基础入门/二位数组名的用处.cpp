#include<iostream>
using namespace std;

int main() {

	//��ά�����������;

	//1�����Բ鿴ռ���ڴ�ռ��С
	int arr[2][3] = {
		{1,2,3},
		{4,5,6}
	};
	cout << "��λ����ռ�õ��ڴ�ռ�Ϊ��" << sizeof(arr) << endl;
	cout << "��λ�����һ��ռ�õ��ڴ�Ϊ��" << sizeof(arr[0]) << endl;
	cout << "��λ�����һ��Ԫ��ռ�õ��ڴ�Ϊ��" << sizeof(arr[0][0]) << endl;

	cout << "��ά��������" << sizeof(arr) / sizeof(arr[0]) << endl;
	cout << "��ά��������" << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;


	//2�����Բ鿴��ά������׵�ַ
	cout << "��λ�����׵�ַ��" << arr << endl;
	cout << "��λ�����һ�е�ַ��" << arr[0] << endl;
	cout << "��λ����ڶ��е�ַ��" << arr[1] << endl;
	//���ʾ���Ԫ�ص��׵�ַ��Ҫ��ȡֵ�� &
	cout << "��λ�����һ��Ԫ�صĵ�ַ��" << &arr[0][0] << endl;
	cout << "��λ����ڶ���Ԫ�صĵ�ַ��" << &arr[0][1] << endl;


	system("pause");

	return 0;
}