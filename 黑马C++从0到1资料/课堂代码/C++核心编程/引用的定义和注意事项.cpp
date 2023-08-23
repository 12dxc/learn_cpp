#include<iostream>;
using namespace std;



int main() {
	//引用的基本语法
	//数据类型  &别名 = 原名

	int a = 10;
	//创建引用
	int& b = a;
	cout <<"a=" << a << endl;
	cout <<"b=" << b << endl;


	//引用的注意事项
	// 1、引用必须初始化
	//int& c;   未初始化，则报错

	//2、引用一旦初始化后，就不可以更改
	int c = 20;
	b = c;    //赋值操作，而不是更改引用

	system("pause");
	return 0;
}