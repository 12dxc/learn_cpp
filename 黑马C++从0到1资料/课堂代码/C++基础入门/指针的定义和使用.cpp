#include<iostream>
using namespace std;

int main() {

	//1������һ��ָ��
	int a = 10;
	//ָ�붨����﷨�� �������� * ָ�������;
	int* p;
	p = &a;
	cout << "a�ĵ�ַΪ��" << &a << endl;
	cout << "ָ��pΪ��" << p << endl;

	//2��ʹ��ָ��
	//����ͨ�������õķ�ʽ�ҵ�ָ��ָ����ڴ�
	//ָ��ǰ��*�ţ���������ã��ҵ�ָ��ָ���ڴ��е�����
	*p = 1000;
	cout << "*p=" << *p << endl;
	cout << "a=" << a << endl;


	system("pause");

	return 0;
}