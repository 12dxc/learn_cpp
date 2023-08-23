#include<iostream>
using namespace std;
#include<string>

//�̳��е�ͬ����̬��Ա����ʽ
class Base {
public:
	static int m_A;
	static void func() {
		cout << "Base - static void func()����" << endl;
	}
};

int Base::m_A = 100;
class Son :public Base {
public:
	static int m_A;
	static void func() {
		cout << "Son - static void func()����" << endl;
	}
};
int Son::m_A = 200;

//ͬ����̬��Ա����
void test01() {
	Son s;
	//1��ͨ���������
	cout << "ͨ���������:" << endl;
	cout << "Son �� m_A = " << s.m_A << endl;
	cout << "Base �� m_A = " << s.Base::m_A << endl;

	//2��ͨ����������
	cout << "ͨ����������:" << endl;
	cout << "Son �� m_A = " << Son::m_A << endl;
	//��һ��::����ͨ����Ŀ��ʽ���ʣ��ڶ���::������ʸ�����������
	cout << "Base �� m_A = " << Son::Base::m_A << endl;
}

//ͬ����̬����
void test02() {
	//1��ͨ���������
	cout << "ͨ���������:" << endl;
	Son s;
	s.func();
	s.Base::func();

	//2��ͨ����������
	cout << "ͨ����������:" << endl;
	Son::func();
	Son::Base::func();
}
int main() {

	//test01();
	test02();
	system("pause");
	return 0;
}
