#include<iostream>
using namespace std;
#include<string>

//������Ԫ
class Building;

class GoodGay {
public:
	GoodGay();

	void visit();  //�ιۺ���������Building�е�����

	Building* building;
};

class Building {
	//GoodGay�Ǳ���ĺ����ѿ��Է��ʱ�����˽�г�Ա
	friend class GoodGay;
public:
	Building();
public:
	string m_SittingRoom;   //����

private:
	string m_BedRoom;  //����
};

//����д��Ա����
Building::Building() {
	m_BedRoom = "����";
	m_SittingRoom = "����";
}
GoodGay::GoodGay(){
//�������������
	building = new Building;

}
void GoodGay::visit() {
	cout << "�û������ڷ���" << building->m_SittingRoom << endl;
	cout << "�û������ڷ���" << building->m_BedRoom << endl;

};
void test01() {
	GoodGay gg;
	gg.visit();
}
int main() {
	test01();

	system("pause");
	return 0;
}
