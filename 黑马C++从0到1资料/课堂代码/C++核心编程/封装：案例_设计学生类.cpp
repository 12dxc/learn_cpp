#include<iostream>;
using namespace std;
#include<string>

//���һ��ѧ���࣬������������ѧ��
//���Ը�������ѧ�Ÿ�ֵ��������ʾѧ����������ѧ��
class Student {
public:    //����Ȩ��

	//���е����Ժ���Ϊ  ����ͳһ��Ϊ ��Ա
	//����   ��Ա����  ��Ա����
	//��Ϊ   ��Ա��Ϊ  ��Ա����

	//����
	string m_Name;   //����
	int m_Id;        //ѧ��

	//��Ϊ
	//��ʾ������ѧ��
	void showStudent() {
		cout << "������" << m_Name << " ѧ�ţ�" << m_Id << endl;

	}
	//��������ֵ
	void setName(string name) {
		m_Name = name;
	}
	//��ѧ�Ÿ�ֵ
	void setId(int id) {
		m_Id = id;
	}
};
int main() {

	//����һ������ѧ��  ʵ��������
	Student s1;
	//��s1����  �������Ը�ֵ����
	s1.m_Name = "����";
	s1.m_Id = 1;
	//��ʾѧ������Ϣ
	s1.showStudent();

	Student s2;
	//����Ϊ�����Ը�ֵ
	s2.setName("����");
	s2.setId(2);
	s2.showStudent();

	system("pause");
	return 0;
}
