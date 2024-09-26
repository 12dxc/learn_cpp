#include<iostream>;
using namespace std;
#include<string>

//成员变量 和 成员函数  是分开存储的
class Person {
	int m_A;  //非静态成员变量  属于类的对象上
	static int m_B;  //静态成员变量  不属于类的对象上
	void func() {   //非静态成员函数  不属于类的对象上 

	}
	static void func2() {   //静态成员函数  不属于类的对象上

	}
};
int Person::m_B = 0;

void test01() {
	Person p;
	//空对象内存为：1
	//C++编译器会给每个空对象也分配一个字节的空间，是为了区分空对象占用的内存位置
	//每个空对象也应该有一个独一无二的内存地址
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
