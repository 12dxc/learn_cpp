#include<iostream>
using namespace std;
#include<string>
#include<ctime>

//学生结构体
struct Student {
	//姓名
	string sName;
	//分数
	int score;
};
//老师结构体定义
struct Teacher {
	//姓名
	string tName;
	//学生数组
	struct Student sArray[5];
};
//给老师和学生赋值的函数
void allocataSpace(struct Teacher tArray[], int len) {
	string nameSeed = "ABCDE";
	//给老师赋值
	for (int i = 0; i < len; i++) {
		tArray[i].tName = "Teacher_";
		tArray[i].tName += nameSeed[i];

		//通过循环给每名老师所带的学生赋值
		for (int j = 0; j < 5; j++) {
			tArray[i].sArray[j].sName = "Student_";
			tArray[i].sArray[j].sName += nameSeed[i];
			int random = rand() % 61 + 40;   //40~100
			tArray[i].sArray[j].score = random;

		}

	}
}
//打印所有信息函数
void printInfo(struct Teacher tArray[], int len) {
	for (int i = 0; i < len; i++)
	{
		cout << "老师姓名：" << tArray[i].tName<< endl;
		for (int j = 0; j < 5; j++) {
			cout << "\t学生姓名：" << tArray[i].sArray[j].sName <<
				" 考试分数：" << tArray[i].sArray[j].score << endl;
		}
	}
}
int main() {

	//随机数种子
	srand((unsigned int)time(NULL));

	//1、创建3名老师的数组
	struct Teacher tArray[3];
	//2、通过函数给3名老师的信息赋值，并给老师带的学生信息赋值
	int len = sizeof(tArray) / sizeof(tArray[0]);
	allocataSpace(tArray, len);
	//3、打印所有老师及所带的学生信息
	printInfo(tArray, len);
	system("pause");

	return 0;
}