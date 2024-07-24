#include"Manager.h"

Manager::Manager(int id, string name, int dId)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

void Manager::showInfo()
{
    cout << "职工编号：" << this->m_Id
        << "\t职工姓名：" << this->m_Name
        << "\t职工岗位：" << this->m_DeptId
        << " \t岗位职责：完成老板交给的任务，并给员工下发任务" << endl;
}
string Manager::getDeptName()
{
    return string("经理");
}