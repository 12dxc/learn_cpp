#include<iostream>;
using namespace std;



int main() {
	//���õĻ����﷨
	//��������  &���� = ԭ��

	int a = 10;
	//��������
	int& b = a;
	cout <<"a=" << a << endl;
	cout <<"b=" << b << endl;


	//���õ�ע������
	// 1�����ñ����ʼ��
	//int& c;   δ��ʼ�����򱨴�

	//2������һ����ʼ���󣬾Ͳ����Ը���
	int c = 20;
	b = c;    //��ֵ�����������Ǹ�������

	system("pause");
	return 0;
}