#include<iostream>
using namespace std;

int main() {
	//1���ȴ�ӡ���е���λ����
	int nums = 100;
	while (nums <= 999) {
		//2�������������ҵ�ˮ�ɻ���
		int a = nums % 10;       //��λ
		int b = nums / 10 % 10;  //ʮλ
		int c = nums / 100;      //��λ
		//��ˮ�ɻ��Ŵ�ӡ
		if (a*a*a + b*b*b + c*c*c == nums) {
			cout << nums << endl;
		}
		nums++;
	}
	
	system("pause");

	return 0;
}