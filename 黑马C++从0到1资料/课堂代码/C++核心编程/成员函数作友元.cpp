#include<iostream>
using namespace std;
#include<string>

class Building;
class GoodGay {
public:
	GoodGay();

	void visit();   //��visit�������Է���Building��˽�г�Ա
	void visit2();   //��visit2���������Է���Building��˽�г�Ա

	Building* building;
};

class Building {
	//���߱�����  GoodGay���µ�visit��Ա������Ϊ�����ĺ����ѣ����Է��ʱ����˽�г�Ա
	friend void GoodGay::visit();
public:
	Building();
public:
	string m_SittingRoom;  //����

private:
	string m_BedRoom;   //����
};

//����ʵ�ֳ�Ա����
Building::Building() {
	m_SittingRoom = "����";
	m_BedRoom = "����";
}

GoodGay::GoodGay() {
	building = new Building;
}

void GoodGay::visit() {
	cout << "visit���ڷ��ʣ�" << building->m_SittingRoom << endl;
	cout << "visit���ڷ��ʣ�" << building->m_BedRoom << endl;
}
void GoodGay::visit2() {
	cout << "visit2���ڷ��ʣ�" << building->m_SittingRoom << endl;
	//cout << "visit2���ڷ��ʣ�" << building->m_BedRoom << endl;

}

void test01() {
	GoodGay gg;
	gg.visit();
	gg.visit2();
}

int main() {

	test01();
	system("pause");
	return 0;
}
