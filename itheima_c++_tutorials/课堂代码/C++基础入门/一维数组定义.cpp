#include<iostream>
using namespace std;

int main() {
	
	//数组
	

	//1.数据类型  数组名[ 数组长度 ]; 
	int arr[5];
	//给数组中的元素赋值
	arr[0] = 10;
	//访问数组元素
	cout << arr[0] << endl;

	//2.数据类型  数组名[数组长度] = { 值1，值2 ... };
	int arr[5] = { 1,3,4,5,21};

	//3.数据类型  数组名[] = { 值1，值2 ... };
	int arr3[] = { 1,2,5,32,54};

	system("pause");

	return ;
}