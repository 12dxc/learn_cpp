#include<iostream>
using namespace std;
#include<string>

//继承中的构造和析构的顺序
class Base {
public:
	Base() {
		cout << "Base构造函数调用" << endl;
	}
	~Base() {
		cout << "Base析构函数调用" << endl;
	}
};
class Son :public Base {
public:
	Son() {
		cout << "Son构造函数调用" << endl;
	}
	~Son() {
		cout << "Son析构函数调用" << endl;
	}
};
void test01() {
	Base b;
	Son s;
	//继承中的构造和析构顺序如下：
	//先构造父类，在构造子类，构造的顺序与构造相反
}
int main() {
	test01();
	
	system("pause");
	return 0;
}
