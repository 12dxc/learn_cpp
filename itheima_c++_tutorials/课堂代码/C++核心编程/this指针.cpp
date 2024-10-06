#include<iostream>
using namespace std;
#include<string>

class Person {
public:
	Person(int age) {
		//this指针指向 被调用的成员函数 所属的对象
		this->age = age;
	}
	int age;
	Person& PersonAddAge(Person& p) {
		this->age += p.age;

		//this指向的是p2的指针，而this指向p2这个对象本体
		return *this;
	}
};
//1、解决命名冲突
void test01() {
	Person p1(18);
	//cout << "p1的年龄：" << p1.age << endl;
}
//2、返回对象本身用*this
void test02() {
	Person p1(10);
	Person p2(10);
	//链式编程思想
	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);
	cout << "p2的年龄为：" << p2.age << endl;
}

int main() {

	test01();
	test02();

	system("pause");
	return 0;
}
