#include<iostream>
using namespace std;
#include<string>

//const��ʹ�ó���

struct student
{
	string name;  //����
	int age;      //����
	int score;    //����
};

//���������βθ�Ϊָ�룬���Լ����ڴ�ռ�,���Ҳ��Ḵ���µĸ�������
void printStudent(const student* s) {
	//����const֮��һ�����޸ĵĲ����ͻᱨ�����Է�ֹ�����
	cout << "������" << s->name << " ���䣺" << s->age << " ������" << s->score << endl;
}
int main() {

	//�����ṹ�����
	student s = { "����",18,70 };

	//ͨ��������ӡ�ṹ����Ϣ
	printStudent(&s);
	system("pause");

	return 0;
}