#include<iostream>
using namespace std;

int main() {
	int a = 10;
	int b = 20;
	//1��const ����ָ��  ����ָ��
	//ָ��ָ���ֵ�����Ըģ���ָ���ָ����Ը�
	const int* p = &a;   

	//2��const ���γ���  ָ�볣��
	//ָ���ָ�򲻿��Ըģ�ָ��ָ���ֵ���Ը�
	int* const p2 = &a;   

	//3��const����ָ��ͳ���
	//ָ���ָ�򲻿��Ըģ�ָ��ָ���ֵҲ�����Ը�
	const int* const p3 = &a;

	system("pause");

	return 0;
}