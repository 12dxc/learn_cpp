#include<iostream>
using namespace std;
#include<string>

//函数调用运算符重载

class MyPrint {
public:

	//重载函数调用运输费
	void operator()(string test) {
		cout << test << endl;
	}
};

void MyPrint02(string test) {
	cout << test << endl;
}

void test01() {
	MyPrint myPrint;
	myPrint("hello world");   //由于使用起来类似函数调用，因此称为仿函数
	MyPrint02("hello world");
}

//仿函数非常灵活
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

	//匿名函数对象
	cout << MyAdd()(10, 100) << endl;

}

int main() {
	test01();
	test02();
	system("pause");
	return 0;
}
