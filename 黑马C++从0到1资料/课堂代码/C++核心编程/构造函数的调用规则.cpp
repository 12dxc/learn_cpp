#include<iostream>;
using namespace std;
//���캯���ĵ��ù���
//1������һ�����ͣ�C++���������ٸ�ÿ�������3������
// Ĭ�Ϲ��� ����ʵ�֣�
// �������� ����ʵ�֣�
// �������� ��ֵ������

//2���������д���вι��캯�����������Ͳ����ṩĬ�Ϲ��죬��Ȼ�ṩ��������
//���д�˿������캯�����������Ͳ�����������ͨ���캯��
class Person {
public:
	Person() {
		cout << "�޲ι��캯��!" << endl;
	}
	Person(int age) {
		m_Age = age;
		cout << "�вι��캯��!" << endl;
	}
	Person(const Person& p) {
		m_Age = p.m_Age;
		cout << "�������캯��!" << endl;
	}
	~Person() {
		cout << "��������!" << endl;
	}
	int m_Age;
};

void test01() {
	Person p;
	p.m_Age = 18;

	Person p2(p);

	cout << "p2������Ϊ��" << p2.m_Age << endl;
}

void test02() {
	Person p;
}

int main() {

	test01();
	test02();

	system("pause");
	return 0;
}
