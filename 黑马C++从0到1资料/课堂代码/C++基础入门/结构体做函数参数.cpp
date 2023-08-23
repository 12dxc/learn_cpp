#include<iostream>
using namespace std;
#include<string>

//学生结构体定义
struct student
{
	string name;  //姓名
	int age;      //年龄
	int score;    //分数
};
//打印学生信息函数
//1、值传递
void printStudent(student s) {
	cout << "子函数1  姓名：" << s.name << " 年龄：" << s.age << " 分数:" << s.score << endl;
}

//2、地址传递
void printStudent2(student* p) {
	cout << "子函数2  姓名：" << p->name << " 年龄：" << p->age << " 分数:" << p->score << endl;
}
int main() {

	//结构体做函数参数
	//将学生传入到一个参数，打印学生身上所有的信息

	//创建结构体变量
	student s = { "张三",20,85 };
	printStudent(s); 
	printStudent2(&s);
	system("pause");

	return 0;
}