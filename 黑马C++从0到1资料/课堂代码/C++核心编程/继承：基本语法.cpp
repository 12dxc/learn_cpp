#include<iostream>
using namespace std;
#include<string>

//��ͨʵ��ҳ��
//class Java {
//public:
//	void header() {
//		cout << "��ҳ ������ ��¼ ע�� ... (����ͷ��)" << endl;
//	}
//	void footer() {
//		cout << "�������� �������� վ�ڵ�ͼ ... (�����ײ�)" << endl;
//	}
//	void left() {
//		cout << "Java Python C++ ... (���������б�)" << endl;
//	}
//	void content() {
//		cout << "Javaѧ����Ƶ" << endl;
//	}
//
//};
//
//class Python {
//public:
//	void header() {
//		cout << "��ҳ ������ ��¼ ע�� ... (����ͷ��)" << endl;
//	}
//	void footer() {
//		cout << "�������� �������� վ�ڵ�ͼ ... (�����ײ�)" << endl;
//	}
//	void left() {
//		cout << "Java Python C++ ... (���������б�)" << endl;
//	}
//	void content() {
//		cout << "Pythonѧ����Ƶ" << endl;
//	}
//
//};
//
//class CPP {
//public:
//	void header() {
//		cout << "��ҳ ������ ��¼ ע�� ... (����ͷ��)" << endl;
//	}
//	void footer() {
//		cout << "�������� �������� վ�ڵ�ͼ ... (�����ײ�)" << endl;
//	}
//	void left() {
//		cout << "Java Python C++ ... (���������б�)" << endl;
//	}
//	void content() {
//		cout << "C++ѧ����Ƶ" << endl;
//	}
//
//};

//�̳�ʵ��ҳ��
//����ҳ����
class BasePage {
public:
	void header() {
		cout << "��ҳ ������ ��¼ ע�� ... (����ͷ��)" << endl;
	}
	void footer() {
		cout << "�������� �������� վ�ڵ�ͼ ... (�����ײ�)" << endl;
	}
	void left() {
		cout << "Java Python C++ ... (���������б�)" << endl;
	}
	void content() {
		cout << "C++ѧ����Ƶ" << endl;
	}
};

//�̳п��Լ����ظ��Ĵ���
//�﷨��class ���� : �̳з�ʽ ����
//����  Ҳ��  ������
//���� Ҳ��  ����

//Javaҳ��
class Java :public BasePage {
public:
	void content() {
		cout << "Javaѧ����Ƶ" << endl;
	}
};
//Pythonҳ��
class Python :public BasePage {
public:
	void content() {
		cout << "Pythonѧ����Ƶ" << endl;
	}
};
//C++ҳ��
class CPP :public BasePage {
public:
	void content() {
		cout << "C++ѧ����Ƶ" << endl;
	}
};

void test01() {
	cout << "Java������Ƶҳ�����£�" << endl;
	Java ja;
	ja.header();
	ja.footer();
	ja.content();
	ja.left();

	cout << "-------------------------------" << endl;
	cout << "Python������Ƶҳ�����£�" << endl;
	Python py;
	py.header();
	py.footer();
	py.content();
	py.left();

	cout << "-------------------------------" << endl;
	cout << "C++������Ƶҳ�����£�" << endl;
	CPP cpp;
	cpp.header();
	cpp.footer();
	cpp.content();
	cpp.left();
}

int main() {

	test01();
	system("pause");
	return 0;
}
