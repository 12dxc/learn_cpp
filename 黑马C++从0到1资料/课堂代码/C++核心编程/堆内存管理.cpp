#include<iostream>;
using namespace std;

//1��new�Ļ����﷨
int* func() {
	//�ڶ�������һ�����ε�����
	//new���ص��� ���������͵�ָ��
	int* p = new int(10);
	return p;
}
void test01() {
	int* p = func();
	cout << *p << endl;
	//���������� �г���Ա�����٣�����Ա�����ͷ�
	//������ͷŶ��������ݣ���ʹ�ùؼ��� delete
	delete p;
	cout << *p << endl;   //�ڴ����ͷţ��ٴη��ʻᱨ��
}

//2���ڶ�������new��������
void test02() {
	//����һ��10�������ݵ����飬�ڶ���
	int* arr = new int[10];  //10����������10��Ԫ��

	for (int i = 0; i < 10; i++) {
		arr[i] = i + 100;
	}
	//�ͷŶ�������  Ҫ��[]
	delete[] arr;
}

int main() {

	test01();

	system("pause");
	return 0;
}