#include<iostream>
using namespace std;
#include<string>

//����������ʽ
//1�� �޲��޷�
void test01()
{
	//void a = 10; //�����Ͳ����Դ�������,ԭ���޷������ڴ�
	cout << "this is test01" << endl;
	//test01(); ��������
}

//2�� �в��޷�
void test02(int a)
{
	cout << "this is test02" << endl;
	cout << "a = " << a << endl;
}

//3���޲��з�
int test03()
{
	cout << "this is test03 " << endl;
	return 10;
}

//4���в��з�
int test04(int a, int b)
{
	cout << "this is test04 " << endl;
	int sum = a + b;
	return sum;
}

int main() {

	system("pause");

	return 0;
}
