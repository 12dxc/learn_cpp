#include<iostream>;
using namespace std;
//构造函数的调用规则
//1、创建一个类型，C++编译器至少给每个类添加3个函数
// 默认构造 （空实现）
// 析构函数 （空实现）
// 拷贝构造 （值拷贝）

//2、如果我们写了有参构造函数，编译器就不在提供默认构造，依然提供拷贝构造
//如果写了拷贝构造函数，编译器就不再其他的普通构造函数
class Person {
public:
	Person() {
		cout << "无参构造函数!" << endl;
	}
	Person(int age) {
		m_Age = age;
		cout << "有参构造函数!" << endl;
	}
	Person(const Person& p) {
		m_Age = p.m_Age;
		cout << "拷贝构造函数!" << endl;
	}
	~Person() {
		cout << "析构函数!" << endl;
	}
	int m_Age;
};

void test01() {
	Person p;
	p.m_Age = 18;

	Person p2(p);

	cout << "p2的年龄为：" << p2.m_Age << endl;
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
