#include<iostream>;
using namespace std;
#include<string>

//�����������
//1������������
//2���������
//3�������Ϊ  ��ȡ���������������
//4���ֱ�����ȫ�ֺ����ͳ�Ա����  �ж��������������

class Cude {
public:
	//��ȡ��
	int getL() {
		return m_L;
	}
	//���ó�
	void setL(int l) {
		m_L = l;
	}
	//��ȡ��
	int getW() {
		return m_W;
	}
	//���ÿ�
	void setW(int w) {
		m_W = w;
	}
	//��ȡ��
	int getH() {
		return m_H;
	}
	//���ø�
	void setH(int h) {
		m_H = h;
	}
	//��ȡ���������
	int calculateS() {
		return 6 * m_L * m_L;
	}
	//��ȡ���������
	int calculateV() {
		return m_L * m_W * m_H;
	}
	//���ó�Ա�����ж� �����������Ƿ����
	bool isSameByClass(Cude& c) {
		if (m_L == c.getL() && m_W == c.getW() && m_H == c.getH()) {
			return true;
		}
		else {
			return false;
		}
	}
private:

	int m_L;    //��
	int m_W;    //��
	int m_H;    //��

};

//����ȫ�ֺ����ж� �����������Ƿ����
bool isSame(Cude& c1, Cude& c2) {
	if (c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH()) {
		return true;
	}
	else {
		return false;
	}
}

int main() {

	//�������������
	Cude c1;
	c1.setL(10);
	c1.setW(10);
	c1.setH(10);

	cout << "c1�����Ϊ��" << c1.calculateS() << endl;
	cout << "c1�����Ϊ��" << c1.calculateV() << endl;

	//�����ڶ������������
	Cude c2;
	c2.setL(10);
	c2.setW(10);
	c2.setH(10);

	//����ȫ�ֺ����ж�
	bool ret = isSame(c1, c2);
	if (ret) {
		cout << "ȫ�ֺ����жϣ�c1��c2���" << endl;
	}
	else {
		cout << "ȫ�ֺ����жϣ�c1��c2�����" << endl;
	}
	//���ó�Ա�����ж�
	ret = c1.isSameByClass(c2);
	if (ret) {
		cout << "��Ա�����жϣ�c1��c2���" << endl;
	}
	else {
		cout << "��Ա�����жϣ�c1��c2�����" << endl;
	}

	system("pause");
	return 0;
}
