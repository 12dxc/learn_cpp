#include<iostream>
using namespace std;
#include<ctime>
int main() {
	//������������� ���õ�ǰϵͳʱ���������������ֹ�������ͬ
	srand((unsigned int)time(NULL));


	//1��ϵͳ���������
	int num = rand() % 100 + 1;  // ���� 0+1~99+1 �������
	//cout << num << endl;
	//2����ҽ��в²�
	cout << "������0~99��������Ϸ" << endl;
	int val = 0;
	while (1) {
		cin >> val;
		//3���ж���ҵĲ²�
		//�¶���  �˳���Ϸ
	    //�´�  ��ʾ�µĽṹ ����С�����·��صڶ���
		if (val < num) {
			cout << "��С��" << endl;
		}
		else if (val > num) {
			cout << "�´���" << endl;
		}
		else {
			cout << "�¶���" << endl;	
			break;
		}
	}
	

	system("pause");

	return 0;
}