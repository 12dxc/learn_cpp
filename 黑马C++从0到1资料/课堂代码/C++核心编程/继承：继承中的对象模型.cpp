#include<iostream>
using namespace std;
#include<string>

//继承中的对象模型
class Base {
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son :public Base {
public:
	int m_D;
};

void test01() {
	//父类中所有的非静态成员属性都会被子类继承下去
	//父类中私有成员属性 是被编译器隐藏了，因此访问不到，但仍然会被继承
	cout << "sizeof Son = " << sizeof(Son) << endl;  // 16
}

int main() {

	test01();
	system("pause");
	return 0;
}
