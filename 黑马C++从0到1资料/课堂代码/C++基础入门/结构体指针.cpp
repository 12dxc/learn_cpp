#include<iostream>
using namespace std;
#include<string>

//�ṹ��ָ��

//����ѧ���ṹ��
struct student
{
	//��Ա�б�
	string name;  //����
	int age;      //����
	int score;    //����
};

int main() {

	//1������ѧ���ṹ�����
	student s = { "����",18,100 };

	//2��ͨ��ָ��ָ��ָ��ṹ�����
	student* p = &s;

	//3��ͨ��ָ����ʽṹ������е�����
	//ָ��ͨ�� -> ���������Է��ʳ�Ա
	cout << "������" << p->name << " ���䣺" << p->age << " ������" << p->score << endl;
	system("pause");

	return 0;
}