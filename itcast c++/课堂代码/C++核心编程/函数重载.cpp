#include<iostream>;
using namespace std;

//函数重载
//可以让函数名相同，提高复用性

//函数重载的满足条件
//1、同一个作用域下
//2、函数名称相同
//3、函数参数类型不同，或者个数不同,或者顺序不同
void func() {
	cout << "func 的调用" << endl;
}
void func(int a) {
	cout << "func(int a) 的调用" << endl;
}
void func(double a) {
	cout << "func(double a) 的调用" << endl;
}
void func(int a, double b) {
	cout << "func(int a,double b) 的调用" << endl;
}
void func(double a, int b) {
	cout << "func(double a,int b) 的调用" << endl;
}
//注意事项
//1、函数返回值不可以作为函数重载的条件
//int func() {
//	cout << endl;     //报错
//}
//2、引用作为重载条件
void func2(int& a) {        //int &a = 10;    不合法
	cout << "func2(int &a)调用" << endl;
}
void func2(const int &a) {     //const int &a = 10;   合法   
	cout << "func2(const int &a)调用" << endl;
}
//3、函数重载碰到默认参数
void func3(int a, int b = 20) {
	cout << "func3(int a,int b = 20)调用" << endl;
}
void func3(int a) {
	cout << "func3(int a)调用" << endl;
}
int main() {

	func();
	func(10);
	func(3.14);
	func(10, 3.14);
	func(3.14, 10);

	int a = 10;
	func2(a);
	func2(10);

	//func3(10);   //当函数重载碰到默认参数，出现二义性，报错，尽量避免这种情况
	system("pause");
	return 0;
}
