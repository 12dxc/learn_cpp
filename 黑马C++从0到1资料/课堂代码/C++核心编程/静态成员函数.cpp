#include<iostream>;
using namespace std;
#include<string>

//��̬��Ա����
//1�����ж�����ͬһ������
//2����̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
class Person {
public:
	//��̬��Ա����
	static void func() {
		m_A = 100;   //��̬��Ա�������Է��ʾ�̬��Ա����
		//m_B=200;   ��̬��Ա���������Է��ʣ��Ǿ�̬��Ա��������Ϊ�޷��������ĸ����������   
		cout << "static void func����" << endl;
	}
	static int m_A;    // ��̬��Ա����
	int B;	
private:
	//��̬��Ա����Ҳ�з���Ȩ��
	static void func2() {
		cout << "static void func2����" << endl;
	}
};
int Person::m_A = 0;

void test01() {
	//1��ͨ��������з���
	Person p;
	p.func();
	//2��ͨ���������з���
	Person::func();

	//Person::func2();   ������ʲ���˽�о�̬����
}

int main() {

	test01();

	system("pause");
	return 0;
}
