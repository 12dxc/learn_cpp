#include<iostream>;
using namespace std;
//1�����캯���ķ���͵���

//���ࣺ
//���ղ�������   �޲ι���(Ĭ�Ϲ���) �� �вι���
//��װ���ͷ���   ��ͨ����  ��������
class Person {
public:
	//��ͨ���캯��
	Person() {
		cout << "Person���޲ι��캯������" << endl;
	}
	Person(int a) {
		age = a;
		cout << "Person���вι��캯������" << endl;
	}

	//�������캯��
	Person(const Person &p) {
		//��������������е����ԣ�����������
		age = p.age;
		cout << "Person�Ŀ������캯������" << endl;
	}

	~Person() {
		cout << "Person��������������" << endl;
	}

	int age;
};

//����
void test01() {
	//1�����ŷ�
	Person p1;        //Ĭ�Ϲ��캯������
	Person p2(10);    //�޲ι��캯������
	Person p3(p2);     //�������캯������

	//ע������1�� ����Ĭ�Ϲ��캯������Ҫ��()
	//��Ϊ�������д��룬����������Ϊ��һ��������������������Ϊ�ڴ�������
	Person p1();
	
	//2����ʾ��
	Person p4;
	Person p5 = Person(20);  //�вι���
	Person p6 = Person(p5);  //��������
	Person(20);   // ��������  �ص㣺��ǰ����ִ�н�����ϵͳ������������������

	//ע������2�� ��Ҫ���ÿ������캯������ʼ����������
	//3����ʽת����
	Person p7 = 10;   //�൱�� Person p4 = person(10);
	Person p8 = p7;  //��������
}


int main() {
	
	test01();

	system("pause");
	return 0;
}
