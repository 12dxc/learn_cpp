#include<iostream>;
using namespace std;
#include<string>

//����Ȩ��
//1������Ȩ�� public      ��Ա �����ڿ��Է��� ������Է���
//2������Ȩ�� protected   ��Ա �����ڿ��Է��� ���ⲻ���Է���   �ӿ��Է��ʸ��еı�������
//3��˽��Ȩ�� private     ��Ա �����ڿ��Է��� ���ⲻ���Է���   �Ӳ����Է��ʸ��е�˽������

class Person{
public:     //����Ȩ��
	string m_Name;   //����

protected:  //����Ȩ��
	string m_Car;    //����

private:    //˽��Ȩ��
	int m_Password;   //���п�����

public:
	void func() {
		m_Name = "����";
		m_Car = "������";
		m_Password = 123456;
	}
};


int main() {
	Person p1;

	p1.m_Name = "����";
	//p1.m_Car = "����";     ����Ȩ�������޷�����
	//p1.m_Password = 123;   ˽��Ȩ�������޷�����
	

	system("pause");
	return 0;
}
