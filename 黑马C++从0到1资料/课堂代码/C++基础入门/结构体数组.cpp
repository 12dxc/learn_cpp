#include<iostream>
using namespace std;
#include<string>

//�ṹ������
//1������ṹ������
struct Student {
	//����
	string name;
	//����
	int age;
	//����
	int socre;
};

int main() {

	//2�������ṹ������
	struct Student stuArray[3] = {
		{"����",18,100},
		{"����",17,80},
		{"����",19,60}
	};
    //3�����ṹ�������е�Ԫ�ظ�ֵ
	stuArray[2].name = "����";
	stuArray[2].age = 27;
	stuArray[2].socre = 60;

    //4�������ṹ������
	for (int i = 0; i < 3; i++)
	{
		cout << "������" << stuArray[i].name << " ���䣺" << stuArray[i].age << " ������" << stuArray[i].socre << endl;
	}

	system("pause");

	return 0;
}