#include<iostream>
using namespace std;


//����ͬ�����
//CPU��
class CPU {
public:
	//������㺯��
	virtual void calculate() = 0;
};
//�Կ���
class VideoCard {
public:
	//������ʾ����
	virtual void display() = 0;
};
//�ڴ�����
class Memory {
public:
	//����洢����
	virtual void storage() = 0;
};

//������
class Computer {
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* mem) {
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}
	//�ṩ�����ĺ���
	void work() {
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}
	//�ṩ�������� �ͷ�3���������
	~Computer() {
		//�ͷ�CPU���
		if (m_cpu != NULL) {
			delete m_cpu;
			m_cpu = NULL;
		}
		//�ͷ��Կ����
		if (m_vc != NULL) {
			delete m_vc;
			m_vc = NULL;
		}
		//�ͷ��ڴ����
		if (m_mem != NULL) {
			delete m_mem;
			m_mem = NULL;
		}
	}
private:
	CPU* m_cpu;
	VideoCard* m_vc;
	Memory* m_mem;

};

//����Ӳ������
//Intel����
class IntelCPU :public CPU {
public:
	virtual void calculate() {
		cout << "intel��CPU��ʼ�����ˣ�" << endl;
	}
};
class IntelVideoCard :public VideoCard {
public:
	virtual void display() {
		cout << "intel���Կ���ʼ��ʾ��!" << endl;
	}
};
class IntelMemory :public Memory {
public:
	virtual void storage() {
		cout << "intel���ڴ濪ʼ�洢�ˣ�" << endl;
	}
};

//Lenovo����
class LenovoCPU :public CPU {
public:
	virtual void calculate() {
		cout << "Lenovo��CPU��ʼ�����ˣ�" << endl;
	}
};
class LenovoVideoCard :public VideoCard {
public:
	virtual void display() {
		cout << "Lenovo���Կ���ʼ��ʾ��!" << endl;
	}
};
class LenovoMemory :public Memory {
public:
	virtual void storage() {
		cout << "Lenovo���ڴ濪ʼ�洢�ˣ�" << endl;
	}
};

void test01() {
	cout << "��һ̨���Կ�ʼ����" << endl;
	//��һ̨�������
	CPU* intelCPU = new IntelCPU;
	VideoCard* intelCard = new IntelVideoCard;
	Memory* intelMem = new IntelMemory;

	//������һ̨����
	Computer* computer1 = new Computer(intelCPU, intelCard, intelMem);
	computer1->work();
	delete computer1;

	cout << "-----------------------------" << endl;
	cout << "�ڶ�̨���Կ�ʼ����" << endl;
	//�ڶ�̨������װ
	Computer* computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
	computer2->work();
	delete computer2;
}

int main() {
	test01();
	system("pause");
	return 0;
}
