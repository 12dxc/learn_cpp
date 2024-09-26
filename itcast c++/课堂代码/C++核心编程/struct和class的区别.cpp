#include<iostream>;
using namespace std;
#include<string>

class C1 {
	int m_A;   //默认权限  私有
};
struct C2 {
	int m_A;    //默认权限  共有
};

int main() {
/*
struct和class区别：
   struct  默认权限为  公共  public
   class   默认权限为  私有  private
*/

	C1 c1;
	//c1.m_A = 100;   不可访问 报错

	C2 c2;
	c2.m_A = 100;   // 可以访问

	system("pause");
	return 0;
}
