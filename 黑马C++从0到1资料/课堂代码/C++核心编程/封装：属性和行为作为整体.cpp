#include<iostream>;
using namespace std;
#define PI 3.14
//���һ��Բ�࣬��Բ���ܳ�
//Բ���ܳ��Ĺ�ʽ�� 2 * PI * �뾶

//class �������һ���࣬���������ŵľ���������
class Circle {
	//����Ȩ��
public:         //����Ȩ��

	//����
	int r;

	//��Ϊ
	double calculateZC() {
		return 2 * PI * r;
	}
};
int main() {
	//ͨ��Բ�� ���������Բ������
	//ʵ������ ��ͨ��һ���� ����һ������Ĺ��̣�
	Circle cl;
	//��Բ���� �����Ը�ֵ
	cl.r = 10;
	cout << "Բ���ܳ�Ϊ��" << cl.calculateZC() << endl;

	system("pause");
	return 0;
}
