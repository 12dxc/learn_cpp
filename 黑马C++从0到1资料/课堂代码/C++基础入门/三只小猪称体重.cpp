#include<iostream>
using namespace std;

int main() {
	//��ֻС������أ��ж���ֻ����
	
	//1��������ֻС������ر���
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;


	//2�����û�������ֻС�������
	cout << "��������ֻС������أ��������ֱַ���A��B��C" << endl;
	cin >> num1;
	cin >> num2;
	cin >> num3;


	//3���ж���ֻ����
	//�ж�A��B������
	if (num1 > num2) {  // A��B��
		if (num1 > num3) {  // A��C��
			cout << "С��A����" << endl;
		}
		else {  // C��A��
			cout << "С��C����" << endl;

		}
	}
	else{   // B��A��
		if (num2 > num3) {  // B��C��
			cout << "С��B����" << endl;

		}
		else {  // C��B��
			cout << "С��C����" << endl;

		}
	}

	system("pause");

	return 0;
}