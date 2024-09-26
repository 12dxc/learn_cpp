#include<iostream>
using namespace std;


//抽象不同零件类
//CPU类
class CPU {
public:
	//抽象计算函数
	virtual void calculate() = 0;
};
//显卡类
class VideoCard {
public:
	//抽象显示函数
	virtual void display() = 0;
};
//内存条类
class Memory {
public:
	//抽象存储函数
	virtual void storage() = 0;
};

//电脑类
class Computer {
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* mem) {
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}
	//提供工作的函数
	void work() {
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}
	//提供析构函数 释放3个电脑零件
	~Computer() {
		//释放CPU零件
		if (m_cpu != NULL) {
			delete m_cpu;
			m_cpu = NULL;
		}
		//释放显卡零件
		if (m_vc != NULL) {
			delete m_vc;
			m_vc = NULL;
		}
		//释放内存零件
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

//具体硬件厂商
//Intel厂商
class IntelCPU :public CPU {
public:
	virtual void calculate() {
		cout << "intel的CPU开始计算了！" << endl;
	}
};
class IntelVideoCard :public VideoCard {
public:
	virtual void display() {
		cout << "intel的显卡开始显示了!" << endl;
	}
};
class IntelMemory :public Memory {
public:
	virtual void storage() {
		cout << "intel的内存开始存储了！" << endl;
	}
};

//Lenovo厂商
class LenovoCPU :public CPU {
public:
	virtual void calculate() {
		cout << "Lenovo的CPU开始计算了！" << endl;
	}
};
class LenovoVideoCard :public VideoCard {
public:
	virtual void display() {
		cout << "Lenovo的显卡开始显示了!" << endl;
	}
};
class LenovoMemory :public Memory {
public:
	virtual void storage() {
		cout << "Lenovo的内存开始存储了！" << endl;
	}
};

void test01() {
	cout << "第一台电脑开始工作" << endl;
	//第一台电脑零件
	CPU* intelCPU = new IntelCPU;
	VideoCard* intelCard = new IntelVideoCard;
	Memory* intelMem = new IntelMemory;

	//创建第一台电脑
	Computer* computer1 = new Computer(intelCPU, intelCard, intelMem);
	computer1->work();
	delete computer1;

	cout << "-----------------------------" << endl;
	cout << "第二台电脑开始工作" << endl;
	//第二台电脑组装
	Computer* computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
	computer2->work();
	delete computer2;
}

int main() {
	test01();
	system("pause");
	return 0;
}
