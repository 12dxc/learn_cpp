#include<iostream>;
using namespace std;

//打印数据函数
void showValue(const int &val) {
	//val = 1000;
	cout << "val = " << val << endl;
}

int main() {
	
	//常量引用
	//使用场景：用来修饰形参，防止误操作

	//加上const之后，编译器将代码修改 int temp = 10; const int & ref = temp;
	const int& ref = 10;  //引用必须引一块合法的内存空间
	
	//函数利用常量引用防止误操作实参
	int a = 100;
	showValue(a);

	system("pause");
	return 0;
}
