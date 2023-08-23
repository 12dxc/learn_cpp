#include"Boss.h"

Boss::Boss(int id, string name, int dId)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

void Boss::showInfo()
{
    cout << "职工编号：" << this->m_Id
        << "\t职工姓名：" << this->m_Name
        << "\t职工岗位：" << this->m_DeptId
        << " \t岗位职责：给经理布置任务" << endl;
}
string Boss::getDeptName()
{
    return string("老板");
}