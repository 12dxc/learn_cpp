#include<iostream>
using namespace std;
#include<string>

//1�����Ӱ��ṹ��
struct Hero {
	//����
	string name;
	//����
	int age;
	//�Ա�
	string sex;
};

//ð������
void bubbleSort(struct Hero heroArray[], int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			//���j�±��Ԫ���������j+1�±��Ԫ�����䣬��������Ԫ��
			if (heroArray[j].age > heroArray[j + 1].age) {
				Hero temp = heroArray[j];
				heroArray[j] = heroArray[j + 1];
				heroArray[j + 1] = temp;
			}
		}
	}
}

//��ӡ����������е���Ϣ
void printHero(struct Hero heroArray[], int len) {
	for (int i = 0; i < len; i++) {
		cout << "������" << heroArray[i].name << " ���䣺" << heroArray[i].age << " �Ա�" << heroArray[i].sex << endl;
	}
}
int main() {

	//2������������5��Ӣ��
	struct Hero heroArray[5] = {
		{"����", 23, "��"},
		{ "����",22,"��" },
		{ "�ŷ�",20,"��" },
		{ "����",21,"��" },
		{ "����",19,"Ů" },
	};
	int len = sizeof(heroArray) / sizeof(heroArray[0]);
	cout << "����ǰ��ӡ��" << endl;
	printHero(heroArray, len);
	//3��������������򣬰������������������
	bubbleSort(heroArray, len);
	//4���������Ľṹ��ӡ���
	cout << "������ӡ��" << endl;
	printHero(heroArray, len);
	system("pause");

	return 0;
}