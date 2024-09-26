#include<iostream>
using namespace std;
#include<string>

//继承方式

//公共继承
class Base1 {
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};
class Son1 :public Base1 {
public:
	void func() {
		m_A = 10;   //父类的公共权限 到子类依然是公共权限
		m_B = 10;	//父类的保护权限 到子类依然是保护权限
		//m_C = 10;	  父类的私有权限 子类访问不到
	}
};

void test01() {
	Son1 s1;
	s1.m_A = 100;
	//s1.m_B = 100;  到Son1中 m_B是访问权限 类外访问不到

}

//保护继承
class Base2 {
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};
class Son2 :protected Base2 {
public:
	void func() {
		m_A = 100;   //父类中公共成员 到子类变为保护权限
		m_B = 100;   //父类中保护成员 到子类变为保护权限
		//m_C = 100;   //父类中私有成员 子类访问不到
	}
};

void test02() {
	Son2 s1;
	//s1.m_A = 1000;  //在Son2中 m_A变为保护权限，因此类外访问不到
	//s1.m_B = 1000;  //在Son2中 m_B保护权限，不可以访问
}

//私有继承
class Base3 {
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};
class Son3 :private Base3 {
public:
	void func() {
		m_A = 100;     //父类中公共成员 到子类变为私有成员
		m_B = 100;     //父类中保护成员 到子类变为私有成员
		//m_C = 100;   //父类中私有成员 子类访问不到
	}
};

void test03() {
	Son3 s1;
	//s1.m_A = 1000;   //到了Son3中变为私有成员 类外访问不到
	//s1.m_B = 1000;   //到了Son3中变为私有成员 类外访问不到
}
class GrandSon3 :public Son3 {
public:
	void func() {
		//m_A = 100;  //到了Son3中 m_A变为私有，即使是子对象也访问到不
		//m_B = 100;  //到了Son3中 m_B变为私有，即使是子对象也访问到不
	}
};
int main() {

	test01();
	test02();
	test03();
	system("pause");
	return 0;
}
