#include<iostream>
using namespace std;

int main() {
	
	//�߼������ - ��  ��
	int a = 10;
	//��c++�У�����0��Ϊ��
	cout << !a << endl;  // 0
    cout << !!a << endl;  // 1


	//�߼������ - ��  &&
	int b = 10;
	int c = 10;
	cout << (b && c) << endl;  // 1
	
	b = 10;
	c = 0;
	cout << (b && c) << endl;  // 0

	b = 0;
	c = 0;
	cout << (b && c) << endl;  // 0
	//�ھ���ͬ��Ϊ�棬����Ϊ��

	
	//�߼������ - ��  ||
	int d = 10;
	int e = 10;
	cout << (d || e) << endl;  // 1

	d = 0;
	e = 10;
	cout << (d || e) << endl;  // 1

	d = 0;
	e = 0;
	cout << (d || e) << endl;  // 0
	//�ھ���ͬ��Ϊ�٣�����Ϊ��

	system("pause");

	return 0;
}