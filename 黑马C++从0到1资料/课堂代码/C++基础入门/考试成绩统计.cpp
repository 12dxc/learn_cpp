#include<iostream>
using namespace std;
#include<string>
int main() {

	//��ά���鰸��-���Գɼ�ͳ��

	//1��������ά����
	int score[3][3] = {
		{100,100,100},
		{90,50,100},
		{60,70,80}
	};

	string names[3] = { "����","����","����" };
	//2��ͳ��ÿ���˵��ܷ�
	for (int i = 0; i < 3; i++){
		int sum = 0;
		for (int j = 0; j < 3; j++) {
			sum += score[i][j];
		}
		cout <<names[i] << "���ܷ֣�" << sum << endl;
	}
	system("pause");

	return 0;
}