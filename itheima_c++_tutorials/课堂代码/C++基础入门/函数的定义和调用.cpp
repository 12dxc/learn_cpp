#include<iostream>
using namespace std;
#include<string>

//函数的定义

//语法：
/*返回值类型  函数名（参数列表）{
      函数体语句 
      返回值
}*/

//定义加法函数
//函数定义时，num1和num2并没有真实数据，他只是一个形式上的参数，简称形参
int add(int num1, int num2) {
	int sum = num1 + num2;
	return sum;
}

int main() {

	int a = 10;
	int b = 20;
	//函数调用语法：函数名称（参数）
	//a和b称为实际参数
	//当调用函数时，实参的值会传递给形参
	cout << add(a, b) << endl;


	system("pause");
	
	return 0;
}
