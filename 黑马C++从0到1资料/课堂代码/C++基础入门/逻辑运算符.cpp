#include<iostream>
using namespace std;

int main() {
	
	//逻辑运算符 - 非  ！
	int a = 10;
	//在c++中，除了0都为真
	cout << !a << endl;  // 0
    cout << !!a << endl;  // 1


	//逻辑运输符 - 与  &&
	int b = 10;
	int c = 10;
	cout << (b && c) << endl;  // 1
	
	b = 10;
	c = 0;
	cout << (b && c) << endl;  // 0

	b = 0;
	c = 0;
	cout << (b && c) << endl;  // 0
	//口诀：同真为真，其余为假

	
	//逻辑运输符 - 或  ||
	int d = 10;
	int e = 10;
	cout << (d || e) << endl;  // 1

	d = 0;
	e = 10;
	cout << (d || e) << endl;  // 1

	d = 0;
	e = 0;
	cout << (d || e) << endl;  // 0
	//口诀：同假为假，其余为真

	system("pause");

	return 0;
}