#include<iostream>
using namespace std;
#include<string>

//�̳��еĶ���ģ��
class Base {
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son :public Base {
public:
	int m_D;
};

void test01() {
	//���������еķǾ�̬��Ա���Զ��ᱻ����̳���ȥ
	//������˽�г�Ա���� �Ǳ������������ˣ���˷��ʲ���������Ȼ�ᱻ�̳�
	cout << "sizeof Son = " << sizeof(Son) << endl;  // 16
}

int main() {

	test01();
	system("pause");
	return 0;
}
