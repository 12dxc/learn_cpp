#include<iostream>
using namespace std;

int main() {
	int a = 10;
	int b = 20;
	//1、const 修饰指针  常量指针
	//指针指向的值不可以改，但指针的指向可以改
	const int* p = &a;   

	//2、const 修饰常量  指针常量
	//指针的指向不可以改，指针指向的值可以改
	int* const p2 = &a;   

	//3、const修饰指针和常量
	//指针的指向不可以改，指针指向的值也不可以改
	const int* const p3 = &a;

	system("pause");

	return 0;
}