#include<iostream>
using namespace std;
#include<string>

//ѧ���ṹ�嶨��
struct student
{
	string name;  //����
	int age;      //����
	int score;    //����
};
//��ӡѧ����Ϣ����
//1��ֵ����
void printStudent(student s) {
	cout << "�Ӻ���1  ������" << s.name << " ���䣺" << s.age << " ����:" << s.score << endl;
}

//2����ַ����
void printStudent2(student* p) {
	cout << "�Ӻ���2  ������" << p->name << " ���䣺" << p->age << " ����:" << p->score << endl;
}
int main() {

	//�ṹ������������
	//��ѧ�����뵽һ����������ӡѧ���������е���Ϣ

	//�����ṹ�����
	student s = { "����",20,85 };
	printStudent(s); 
	printStudent2(&s);
	system("pause");

	return 0;
}