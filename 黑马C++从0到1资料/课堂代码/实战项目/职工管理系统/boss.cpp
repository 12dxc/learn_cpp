#include"Boss.h"

Boss::Boss(int id, string name, int dId)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

void Boss::showInfo()
{
    cout << "ְ����ţ�" << this->m_Id
        << "\tְ��������" << this->m_Name
        << "\tְ����λ��" << this->m_DeptId
        << " \t��λְ�𣺸�����������" << endl;
}
string Boss::getDeptName()
{
    return string("�ϰ�");
}