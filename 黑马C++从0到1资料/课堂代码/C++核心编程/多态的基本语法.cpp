#include<iostream>
using namespace std;
#include<string>

//��̬

//������
class Animal {
public:
	//�麯��
	virtual void speak() {
		cout << "������˵��" << endl;
	}
};

//è��
class Cat :public Animal {
public:
	//��д������ ��������ֵ���� ������ �����б���ȫ��ͬ
	void speak() {
		cout << "Сè��˵��" << endl;
	}
};
//����
class Dog :public Animal {
public:
	void speak() {
		cout << "С����˵��" << endl;
	}
};

//ִ��˵���ĺ���
//��ַ��� �ڱ���׶ξ�ȷ��������ַ
//�����ִ����è˵������ô���������ַ�Ͳ�����ǰ�󶨣���Ҫ�����н׶ν��а󶨣������

//��̬��̬����������
//1���м̳й�ϵ
//2������Ҫ��д�����麯��

//��̬��̬ʹ��
//�����ָ������� ָ���������

void doSpeak(Animal& animal) {  //Animal & animal = cat;
	animal.speak();
}

void test01() {
	Cat cat;
	doSpeak(cat);

	Dog dog;
	doSpeak(dog);
}

int main() {

	test01();
	system("pause");
	return 0;
}
