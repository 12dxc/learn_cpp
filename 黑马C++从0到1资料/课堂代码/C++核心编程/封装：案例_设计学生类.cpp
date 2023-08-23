#include<iostream>;
using namespace std;
#include<string>

//设计一个学生类，属性有姓名和学号
//可以给姓名和学号赋值，可以显示学生的姓名和学号
class Student {
public:    //公共权限

	//类中的属性和行为  我们统一称为 成员
	//属性   成员属性  成员变量
	//行为   成员行为  成员方法

	//属性
	string m_Name;   //姓名
	int m_Id;        //学号

	//行为
	//显示姓名和学号
	void showStudent() {
		cout << "姓名：" << m_Name << " 学号：" << m_Id << endl;

	}
	//给姓名赋值
	void setName(string name) {
		m_Name = name;
	}
	//给学号赋值
	void setId(int id) {
		m_Id = id;
	}
};
int main() {

	//创建一个具体学生  实例化对象
	Student s1;
	//给s1对象  进行属性赋值操作
	s1.m_Name = "张三";
	s1.m_Id = 1;
	//显示学生的信息
	s1.showStudent();

	Student s2;
	//用行为给属性赋值
	s2.setName("李四");
	s2.setId(2);
	s2.showStudent();

	system("pause");
	return 0;
}
