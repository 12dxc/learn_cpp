#include<iostream>
using namespace std;
#include<fstream>

//�������ļ�  д�ļ�

class Person {
public:
	char m_Name[64];  //����
	int m_Age;    //����
};

void test01() {
	//1������������
	ofstream ofs;

	//2�����ļ�
	ofs.open("person.txt", ios::out | ios::binary);

	//3��д�ļ�
	Person p = { "����",18 };
	ofs.write((const char*)&p,sizeof(Person));
	//4���ر��ļ�
	ofs.close();
}

int main() {
	
	test01();
	system("pause");
	return 0;
}
