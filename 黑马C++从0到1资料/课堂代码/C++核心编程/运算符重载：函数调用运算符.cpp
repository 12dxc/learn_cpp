#include<iostream>
using namespace std;
#include<string>

//�����������������

class MyPrint {
public:

	//���غ������������
	void operator()(string test) {
		cout << test << endl;
	}
};

void MyPrint02(string test) {
	cout << test << endl;
}

void test01() {
	MyPrint myPrint;
	myPrint("hello world");   //����ʹ���������ƺ������ã���˳�Ϊ�º���
	MyPrint02("hello world");
}

//�º����ǳ����
class MyAdd {
public:
	int operator()(int num1,int num2) {
		return num1 + num2;
	}
};
void test02() {
	MyAdd myadd;
	int ret=myadd(1, 100);
	cout << "ret = " << ret << endl;

	//������������
	cout << MyAdd()(10, 100) << endl;

}

int main() {
	test01();
	test02();
	system("pause");
	return 0;
}
