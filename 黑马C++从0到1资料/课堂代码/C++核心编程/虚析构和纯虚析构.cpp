#include<iostream>
using namespace std;
#include<string>

//���麯���ͳ�����
class Base {
public:
	//���麯��
	//ֻҪ��һ�����麯������������Ϊ������
	//�������ص㣺
	//1���޷�ʵ��������
	//2�������������  ������д�����еĴ��麯��������Ҳ���ڳ�����
	virtual void func() = 0;
};

class Son :public Base {
public:
	void func() {
		cout << "func��������" << endl;
	}
};

void test01() {
	//Base b;   //�������޷�ʵ��������
	//Son s;    //���������д�����еĴ��麯���������޷�ʵ��������

	Base* base = new Son;
	base->func();
	
}

int main() {

	test01();
	system("pause");
	return 0;
}
