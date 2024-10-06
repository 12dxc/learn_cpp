#include<iostream>
using namespace std;

int main() {

	//1、单精度 float
	//2、双精度 double

	//默认情况下 输出一个小数，会显示6位有效数字
	float f1 = 3.1415926f;  //默认情况为double，需在末尾加f，声明为单精度
	cout << "f1=" << f1 << endl;
	double d1 = 3.1415926;
	cout << "f1=" << f1 << endl;

	//统计float和double占用内存空间
	cout << "float 占用内存空间为：" << sizeof(float) << endl; //4字节
	cout << "double 占用内存空间为：" << sizeof(double) << endl; //8字节

	//科学计数法
	float f2 = 3e2;  //3 * 10^2
	cout << "f2=" << f2 << endl; 
	float f3 = 3e-2;  //3 * 0.1^2
	cout << "f3=" << f3 << endl;

	system("pause");

	return 0;
}