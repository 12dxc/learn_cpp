#include<iostream>;
using namespace std;

//��������
//�����ú�������ͬ����߸�����

//�������ص���������
//1��ͬһ����������
//2������������ͬ
//3�������������Ͳ�ͬ�����߸�����ͬ,����˳��ͬ
void func() {
	cout << "func �ĵ���" << endl;
}
void func(int a) {
	cout << "func(int a) �ĵ���" << endl;
}
void func(double a) {
	cout << "func(double a) �ĵ���" << endl;
}
void func(int a, double b) {
	cout << "func(int a,double b) �ĵ���" << endl;
}
void func(double a, int b) {
	cout << "func(double a,int b) �ĵ���" << endl;
}
//ע������
//1����������ֵ��������Ϊ�������ص�����
//int func() {
//	cout << endl;     //����
//}
//2��������Ϊ��������
void func2(int& a) {        //int &a = 10;    ���Ϸ�
	cout << "func2(int &a)����" << endl;
}
void func2(const int &a) {     //const int &a = 10;   �Ϸ�   
	cout << "func2(const int &a)����" << endl;
}
//3��������������Ĭ�ϲ���
void func3(int a, int b = 20) {
	cout << "func3(int a,int b = 20)����" << endl;
}
void func3(int a) {
	cout << "func3(int a)����" << endl;
}
int main() {

	func();
	func(10);
	func(3.14);
	func(10, 3.14);
	func(3.14, 10);

	int a = 10;
	func2(a);
	func2(10);

	//func3(10);   //��������������Ĭ�ϲ��������ֶ����ԣ��������������������
	system("pause");
	return 0;
}
