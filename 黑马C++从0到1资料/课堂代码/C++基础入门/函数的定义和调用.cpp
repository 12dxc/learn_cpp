#include<iostream>
using namespace std;
#include<string>

//�����Ķ���

//�﷨��
/*����ֵ����  �������������б�{
      ��������� 
      ����ֵ
}*/

//����ӷ�����
//��������ʱ��num1��num2��û����ʵ���ݣ���ֻ��һ����ʽ�ϵĲ���������β�
int add(int num1, int num2) {
	int sum = num1 + num2;
	return sum;
}

int main() {

	int a = 10;
	int b = 20;
	//���������﷨���������ƣ�������
	//a��b��Ϊʵ�ʲ���
	//�����ú���ʱ��ʵ�ε�ֵ�ᴫ�ݸ��β�
	cout << add(a, b) << endl;


	system("pause");
	
	return 0;
}
