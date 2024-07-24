#include<iostream>;
using namespace std;

//1、new的基本语法
int* func() {
	//在堆区创建一个整形的数据
	//new返回的是 该数据类型的指针
	int* p = new int(10);
	return p;
}
void test01() {
	int* p = func();
	cout << *p << endl;
	//堆区的数据 有程序员管理开辟，程序员管理释放
	//如果想释放堆区的数据，则使用关键字 delete
	delete p;
	cout << *p << endl;   //内存已释放，再次访问会报错
}

//2、在堆区利用new开辟数组
void test02() {
	//创建一个10整形数据的数组，在堆区
	int* arr = new int[10];  //10代表数组有10个元素

	for (int i = 0; i < 10; i++) {
		arr[i] = i + 100;
	}
	//释放堆区数组  要加[]
	delete[] arr;
}

int main() {

	test01();

	system("pause");
	return 0;
}