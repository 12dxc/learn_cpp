#include<iostream>
using namespace std;
#include<string>

//�̳з�ʽ

//�����̳�
class Base1 {
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};
class Son1 :public Base1 {
public:
	void func() {
		m_A = 10;   //����Ĺ���Ȩ�� ��������Ȼ�ǹ���Ȩ��
		m_B = 10;	//����ı���Ȩ�� ��������Ȼ�Ǳ���Ȩ��
		//m_C = 10;	  �����˽��Ȩ�� ������ʲ���
	}
};

void test01() {
	Son1 s1;
	s1.m_A = 100;
	//s1.m_B = 100;  ��Son1�� m_B�Ƿ���Ȩ�� ������ʲ���

}

//�����̳�
class Base2 {
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};
class Son2 :protected Base2 {
public:
	void func() {
		m_A = 100;   //�����й�����Ա �������Ϊ����Ȩ��
		m_B = 100;   //�����б�����Ա �������Ϊ����Ȩ��
		//m_C = 100;   //������˽�г�Ա ������ʲ���
	}
};

void test02() {
	Son2 s1;
	//s1.m_A = 1000;  //��Son2�� m_A��Ϊ����Ȩ�ޣ����������ʲ���
	//s1.m_B = 1000;  //��Son2�� m_B����Ȩ�ޣ������Է���
}

//˽�м̳�
class Base3 {
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};
class Son3 :private Base3 {
public:
	void func() {
		m_A = 100;     //�����й�����Ա �������Ϊ˽�г�Ա
		m_B = 100;     //�����б�����Ա �������Ϊ˽�г�Ա
		//m_C = 100;   //������˽�г�Ա ������ʲ���
	}
};

void test03() {
	Son3 s1;
	//s1.m_A = 1000;   //����Son3�б�Ϊ˽�г�Ա ������ʲ���
	//s1.m_B = 1000;   //����Son3�б�Ϊ˽�г�Ա ������ʲ���
}
class GrandSon3 :public Son3 {
public:
	void func() {
		//m_A = 100;  //����Son3�� m_A��Ϊ˽�У���ʹ���Ӷ���Ҳ���ʵ���
		//m_B = 100;  //����Son3�� m_B��Ϊ˽�У���ʹ���Ӷ���Ҳ���ʵ���
	}
};
int main() {

	test01();
	test02();
	test03();
	system("pause");
	return 0;
}
