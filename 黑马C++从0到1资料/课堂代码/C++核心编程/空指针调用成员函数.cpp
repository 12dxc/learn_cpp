#include<iostream>
using namespace std;
#include<string>

//��ָ����ó�Ա����

class Person {
public:
	void showClassName() {
		cout << "this is Person class" << endl;
	}
	void showPersonAge() {
		//����ԭ������Ϊ�����ָ��ΪNULL
		if (this == NULL) {
			return;
		}
		cout << "age = " << m_Age << endl;
	}
	int m_Age;
};
void  test01() {
	Person* p = NULL;
	p->showClassName();
	p->showPersonAge();
}
int main() {

	test01();
	system("pause");
	return 0;
}
