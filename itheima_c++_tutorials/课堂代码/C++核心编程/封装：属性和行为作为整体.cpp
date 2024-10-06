#include<iostream>;
using namespace std;
#define PI 3.14
//设计一个圆类，求圆的周长
//圆求周长的公式： 2 * PI * 半径

//class 代表设计一个类，类后面紧跟着的就是类名称
class Circle {
	//访问权限
public:         //公共权限

	//属性
	int r;

	//行为
	double calculateZC() {
		return 2 * PI * r;
	}
};
int main() {
	//通过圆类 创建具体的圆（对象）
	//实例化： （通过一个类 创建一个对象的过程）
	Circle cl;
	//给圆对象 的属性赋值
	cl.r = 10;
	cout << "圆的周长为：" << cl.calculateZC() << endl;

	system("pause");
	return 0;
}
