#include<iostream>;
using namespace std;
#include<string>

//��Ա���� �� ��Ա����  �Ƿֿ��洢��
class Person {
	int m_A;  //�Ǿ�̬��Ա����  ������Ķ�����
	static int m_B;  //��̬��Ա����  ��������Ķ�����
	void func() {   //�Ǿ�̬��Ա����  ��������Ķ����� 

	}
	static void func2() {   //��̬��Ա����  ��������Ķ�����

	}
};
int Person::m_B = 0;

void test01() {
	Person p;
	//�ն����ڴ�Ϊ��1
	//C++���������ÿ���ն���Ҳ����һ���ֽڵĿռ䣬��Ϊ�����ֿն���ռ�õ��ڴ�λ��
	//ÿ���ն���ҲӦ����һ����һ�޶����ڴ��ַ
}
void test02() {
	Person p;
	cout << "sizeof(p) = " << sizeof(p) << endl;
}

int main() {

	test01();
	test02(); 


	system("pause");
	return 0;
}
