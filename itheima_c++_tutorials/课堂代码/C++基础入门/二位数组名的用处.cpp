#include<iostream>
using namespace std;

int main() {

	//二维数组的名称用途

	//1、可以查看占用内存空间大小
	int arr[2][3] = {
		{1,2,3},
		{4,5,6}
	};
	cout << "二位数组占用的内存空间为：" << sizeof(arr) << endl;
	cout << "二位数组第一行占用的内存为：" << sizeof(arr[0]) << endl;
	cout << "二位数组第一个元素占用的内存为：" << sizeof(arr[0][0]) << endl;

	cout << "二维数组行数" << sizeof(arr) / sizeof(arr[0]) << endl;
	cout << "二维数组列数" << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;


	//2、可以查看二维数组的首地址
	cout << "二位数组首地址：" << arr << endl;
	cout << "二位数组第一行地址：" << arr[0] << endl;
	cout << "二位数组第二行地址：" << arr[1] << endl;
	//访问具体元素的首地址需要加取值符 &
	cout << "二位数组第一个元素的地址：" << &arr[0][0] << endl;
	cout << "二位数组第二个元素的地址：" << &arr[0][1] << endl;


	system("pause");

	return 0;
}