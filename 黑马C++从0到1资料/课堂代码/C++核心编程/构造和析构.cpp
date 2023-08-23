#include<iostream>;
using namespace std;

//对象的初始化和清理
class Person {
public:
	//1、构造函数 进行初始化操作
	//没有返回值，不用写void
	//函数名与类名相同
	//构造函数可以有参数，可以发生重载
	//创建对象时，构造函数会自动调用，且只调用一次
	Person() {
		cout << "Person 构造函数的调用" << endl;
	}

	//2、析构函数 进行清理的操作
	//没有返回值 不写 void
	//函数名和类目相同 在名称前加 ~
	//析构函数不可以有参数的，所以不能重载
	//对象在销毁前 会自动调用析构函数，而且只会调用一次
	~Person() {
		cout << "Person 的析构函数调用" << endl;
	}
};
//构造和析构是必须有的实现，如果我能自己不通过，编译器会提供一个空实现的构造和析构
void  test01() {
	Person p;  //在栈上的数据，test01指向完毕后，释放这个对象
}

int main() {
	
	test01();
	system("pause");
	return 0;
}
