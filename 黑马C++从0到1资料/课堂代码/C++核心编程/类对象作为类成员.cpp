#include<iostream>;
using namespace std;
#include<string>
//�������Ϊ���Ա

//�ֻ���
class Phone {
public:
	Phone(string pName) {
		m_PName = pName;
		cout << "Phone��������������" << endl;
	}
	//�ֻ�Ʒ������
	string m_PName;
};
//����
class Person {
public:
	Person(string name, string pName) :m_Name(name), m_Phone(pName) {
		cout << "Person�Ĺ��캯������" << endl;
	}
	//����
	string m_Name;
	//�ֻ�
	Phone m_Phone;
	~Person() {
		cout << "Person��������������" << endl;
	}
};
void test01() {
	Person p("����", "ƻ��13");
	cout << p.m_Name << "����" << p.m_Phone.m_PName << endl;
}
//����������Ϊ�����Ա������ʱ�ȹ���������ڹ�������,������˳���빹���෴
int main() {

	test01();
	system("pause");
	return 0;
}
