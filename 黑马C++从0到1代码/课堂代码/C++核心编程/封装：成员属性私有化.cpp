#include<iostream>;
using namespace std;
#include<string>

//成员属性设置为私有
//1、可以自己控制读写权限
//2、对于写可以检测数据的有效性

//设计人类
class Person {
public:
	//设置姓名
	void setName(string name) {
		m_Name = name;
	}
	//获取姓名  
	string getName() {
		return m_Name;
	}
	//获取年龄   
	int getAge() {
		return m_Age;
	}
	//设置情人
	void setLover(string lover) {
		m_Lover = lover;
	}
	//新增设置年龄接口  但范围必须在0 ~ 150之间
	void setAge(int age) {
		if (age < 0 || age > 150){
			m_Age = 0;
			cout << "您输入的年龄有误" << endl;
			return;
		}
		m_Age = age;
	}
private:
	//姓名  可读可写
	string m_Name;
	//年龄  只读
	int m_Age;
	//情人  只写
	string m_Lover;
};

int main() {
	Person p;
	p.setName("张三");
	cout << "姓名：" << p.getName() << endl;

	/*p.m_Age = 18;
	p.setAge(18);   未设置修改权限  报错    */
	cout << "年龄" << p.getAge() << endl;

	p.setLover("莉米亚");
	//cout << "情人" << p.getLover() << endl;    未设置可读权限  报错

	p.setAge(1000);
	cout <<"修改后的年龄：" << p.getAge() << endl;
	
	system("pause");
	return 0;
}
