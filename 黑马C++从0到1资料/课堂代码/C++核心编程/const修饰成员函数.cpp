#include<iostream>
using namespace std;
#include<string>

//������
class Person {
public:
	//thisָ��ı��� ��ָ�볣��  
	//�ڳ�Ա���������const�����ε���thisָ�룬��ָ��ָ���ֵҲ�����޸�
	void showPerson() const {  
		//m_A = 100;
		//this = NULL;  thisָ�벻�����޸�ָ���ָ��
		m_B = 100;
	}
	void func() {

	}
	int m_A;
	mutable int m_B;   //�����������ʹ�ڳ������У�Ҳ�����޸����ֵ�����Ϲؼ���mutable
};

void  test01() {
	Person p;
	p.showPerson();
}

//������
void  test02() {
	const Person p;   //�ڶ���ǰ��const����Ϊ������
	//p.m_A = 100;
	p.m_B = 100;    //m_B�������ֵ���ڳ�������Ҳ�����޸�
	
	//p.func();    �����󲻿��Ե�����ͨ��Ա��������Ϊ��ͨ��Ա���������޸�����
	p.showPerson();      //������ֻ�ܵ��ó�����
	
}

int main() {

	test01();
	test02();
	system("pause");
	return 0;
}
