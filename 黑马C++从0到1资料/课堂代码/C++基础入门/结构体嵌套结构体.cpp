#include<iostream>
using namespace std;
#include<string>

//����ѧ���ṹ��
struct student
{
	string name;  //����
	int age;      //����
	int score;    //����
};
//������ʦ�ṹ��
struct teacher {
	int id;  //��ʦ�仯
	string name;   //��ʦ����
	int age;   //����
	struct student stu;  //������ѧ��
};

int main() {

	//�ṹ��Ƕ�׽ṹ��
	teacher t;
	t.id = 10000;
	t.name = "����";
	t.age = 50;
	t.stu.name = "С��";
	t.stu.age = 20;
	t.stu.score = 100;

	cout << "��ʦ������" << t.name << " ��ʦ��ţ�" << t.id << " ��ʦ���䣺" << t.age << endl
		<< "��ʦ������ѧ��������" << t.stu.name << " ѧ�����䣺" << t.stu.age << " ѧ��������" << t.stu.score << endl;

	system("pause");

	return 0;
}