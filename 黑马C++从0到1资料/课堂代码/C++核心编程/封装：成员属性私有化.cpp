#include<iostream>;
using namespace std;
#include<string>

//��Ա��������Ϊ˽��
//1�������Լ����ƶ�дȨ��
//2������д���Լ�����ݵ���Ч��

//�������
class Person {
public:
	//��������
	void setName(string name) {
		m_Name = name;
	}
	//��ȡ����  
	string getName() {
		return m_Name;
	}
	//��ȡ����   
	int getAge() {
		return m_Age;
	}
	//��������
	void setLover(string lover) {
		m_Lover = lover;
	}
	//������������ӿ�  ����Χ������0 ~ 150֮��
	void setAge(int age) {
		if (age < 0 || age > 150){
			m_Age = 0;
			cout << "���������������" << endl;
			return;
		}
		m_Age = age;
	}
private:
	//����  �ɶ���д
	string m_Name;
	//����  ֻ��
	int m_Age;
	//����  ֻд
	string m_Lover;
};

int main() {
	Person p;
	p.setName("����");
	cout << "������" << p.getName() << endl;

	/*p.m_Age = 18;
	p.setAge(18);   δ�����޸�Ȩ��  ����    */
	cout << "����" << p.getAge() << endl;

	p.setLover("������");
	//cout << "����" << p.getLover() << endl;    δ���ÿɶ�Ȩ��  ����

	p.setAge(1000);
	cout <<"�޸ĺ�����䣺" << p.getAge() << endl;
	
	system("pause");
	return 0;
}
