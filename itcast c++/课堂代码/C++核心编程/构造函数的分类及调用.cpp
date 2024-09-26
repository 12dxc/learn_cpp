#include<iostream>;
using namespace std;
//1、构造函数的分类和调用

//分类：
//按照参数分类   无参构造(默认构造) 和 有参构造
//安装类型分类   普通构造  拷贝构造
class Person {
public:
	//普通构造函数
	Person() {
		cout << "Person的无参构造函数调用" << endl;
	}
	Person(int a) {
		age = a;
		cout << "Person的有参构造函数调用" << endl;
	}

	//拷贝构造函数
	Person(const Person &p) {
		//将传入的类上所有的属性，拷贝到本类
		age = p.age;
		cout << "Person的拷贝构造函数调用" << endl;
	}

	~Person() {
		cout << "Person的析构函数调用" << endl;
	}

	int age;
};

//调用
void test01() {
	//1、括号法
	Person p1;        //默认构造函数调用
	Person p2(10);    //无参构造函数调用
	Person p3(p2);     //拷贝构造函数调用

	//注意事项1： 调用默认构造函数，不要加()
	//因为下面这行代码，编译器会认为是一个函数的声明，不会认为在创建对象
	Person p1();
	
	//2、显示法
	Person p4;
	Person p5 = Person(20);  //有参构造
	Person p6 = Person(p5);  //拷贝构造
	Person(20);   // 匿名对象  特点：当前函数执行结束后，系统会立即回收匿名对象

	//注意事项2： 不要利用拷贝构造函数，初始化匿名对象
	//3、隐式转换法
	Person p7 = 10;   //相当于 Person p4 = person(10);
	Person p8 = p7;  //拷贝构造
}


int main() {
	
	test01();

	system("pause");
	return 0;
}
