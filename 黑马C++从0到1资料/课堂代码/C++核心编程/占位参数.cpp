#include<iostream>;
using namespace std;

//ռλ����
//�﷨�� ����ֵ����  ���������������ͣ�{ }

//ռλ���� ��������Ĭ��ֵ
void func(int a, int = 10) {
	cout << "this is func" << endl;
}

int main() {

	func(10);

	system("pause");
	return 0;
}
