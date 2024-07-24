#include<iostream>;
using namespace std;

//占位参数
//语法： 返回值类型  函数名（数据类型）{ }

//占位参数 还可以有默认值
void func(int a, int = 10) {
	cout << "this is func" << endl;
}

int main() {

	func(10);

	system("pause");
	return 0;
}
