#include"employee.h"

Employee::Employee(int id,string name, int dId)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

void Employee::showInfo()
{
    cout<<"ְ����ţ�"<<this->m_Id
        <<"\tְ��������"<<this->m_Name
        <<"\tְ����λ��"<<this->m_DeptId
        << " \t��λְ����ɾ�����������" << endl;
}
string Employee::getDeptName()
{
    return string("Ա��");
}