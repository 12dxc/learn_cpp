#include<iostream>;
using namespace std;

//��ӡ���ݺ���
void showValue(const int &val) {
	//val = 1000;
	cout << "val = " << val << endl;
}

int main() {
	
	//��������
	//ʹ�ó��������������βΣ���ֹ�����

	//����const֮�󣬱������������޸� int temp = 10; const int & ref = temp;
	const int& ref = 10;  //���ñ�����һ��Ϸ����ڴ�ռ�
	
	//�������ó������÷�ֹ�����ʵ��
	int a = 100;
	showValue(a);

	system("pause");
	return 0;
}
