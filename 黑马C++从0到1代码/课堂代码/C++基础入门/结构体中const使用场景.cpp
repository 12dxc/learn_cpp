#include<iostream>
using namespace std;
#include<string>

//const的使用场景

struct student
{
	string name;  //姓名
	int age;      //年龄
	int score;    //分数
};

//将函数的形参改为指针，可以减少内存空间,而且不会复制新的副本出来
void printStudent(const student* s) {
	//加入const之后，一旦有修改的操作就会报错，可以防止误操作
	cout << "姓名：" << s->name << " 年龄：" << s->age << " 分数：" << s->score << endl;
}
int main() {

	//创建结构体变量
	student s = { "张三",18,70 };

	//通过函数打印结构体信息
	printStudent(&s);
	system("pause");

	return 0;
}