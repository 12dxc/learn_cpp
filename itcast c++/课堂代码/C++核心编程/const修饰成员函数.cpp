#include<iostream>
using namespace std;
#include<string>

//常函数
class Person {
public:
	//this指针的本质 是指针常量  
	//在成员函数后面加const，修饰的是this指针，让指针指向的值也不能修改
	void showPerson() const {  
		//m_A = 100;
		//this = NULL;  this指针不可以修改指针的指向
		m_B = 100;
	}
	void func() {

	}
	int m_A;
	mutable int m_B;   //特殊变量，即使在常函数中，也可以修改这个值，加上关键字mutable
};

void  test01() {
	Person p;
	p.showPerson();
}

//常对象
void  test02() {
	const Person p;   //在对象前加const，变为常对象
	//p.m_A = 100;
	p.m_B = 100;    //m_B是特殊的值，在常对象下也可以修改
	
	//p.func();    常对象不可以调用普通成员函数，因为普通成员函数可以修改属性
	p.showPerson();      //常函数只能调用常对象
	
}

int main() {

	test01();
	test02();
	system("pause");
	return 0;
}
