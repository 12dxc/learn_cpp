#include<iostream>
using namespace std;
#include<string>

//�̳��еĹ����������˳��
class Base {
public:
	Base() {
		cout << "Base���캯������" << endl;
	}
	~Base() {
		cout << "Base������������" << endl;
	}
};
class Son :public Base {
public:
	Son() {
		cout << "Son���캯������" << endl;
	}
	~Son() {
		cout << "Son������������" << endl;
	}
};
void test01() {
	Base b;
	Son s;
	//�̳��еĹ��������˳�����£�
	//�ȹ��츸�࣬�ڹ������࣬�����˳���빹���෴
}
int main() {
	test01();
	
	system("pause");
	return 0;
}
