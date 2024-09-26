#include "manager.h"

//默认构造
Manager::Manager()
{
}

//有参构造
Manager::Manager(string name, string pwd)
{
    //初始化管理员信息
    this->m_Name = name;
    this->m_Pwd = pwd;

    //初始化容器  获取到所有文件中，老师、学生的信息
    this->initVector();

    //初始化机房信息
    ifstream ifs;
    ifs.open(COMPUTER_FILE, ios::in);

    ComputerRoom c;
    while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
    {
        //将读取的信息放入到容器中
        vCom.push_back(c);
    }
    ifs.close();

}

//选择菜单
void Manager::operMenu()
{

    cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
    cout << "\t\t ---------------------------------\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          1.添加账号            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          2.查看账号            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          3.查看机房            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          4.清空预约            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          0.注销登录            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t ---------------------------------\n";
    cout << "请选择您的操作： " << endl;

}

//添加账号  
void Manager::addPerson()
{
    cout << "请输入添加账号的类型" << endl;
    cout << "1、添加学生" << endl;
    cout << "2、添加老师" << endl;

    string fileName;     //操作文件名
    string tip;       //提示id号
    string errorTip;   //重复错误提示

    ofstream ofs;    //文件操作对象

    int select = 0;
    cin >> select;    //接收用户选择

    if (select == 1)
    {
        //添加的是学生
        fileName = STUDENT_FILE;
        tip = "请输入学号：";
        errorTip = "学号重复，请重新输入";
    }
    else
    {
        //添加的是老师
        fileName = TEACHER_FILE;
        tip = "请输入职工编号：";
        errorTip = "职工号重复，请重新输入";
    }

    //利用追加的方式 写文件
    ofs.open(fileName, ios::out | ios::app);

    int id;   //学号 或 职工号
    string name;   //姓名
    string pwd;    //密码



    cout << tip << endl;
    while (true)
    {
        cin >> id;
        bool ret = checkRepeat(id, select);
        if (ret)  //有重复
        {
            cout << errorTip << endl;
        }
        else
        {
            break;
        }
    }
    cout << "请输入姓名：" << endl;
    cin >> name;
    cout << "请输入密码：" << endl;
    cin >> pwd;

    //向文件中添加数据
    ofs << id << " " << name << " " << pwd << endl;
    cout << "添加成功" << endl;

    system("pause");
    system("cls");

    ofs.close();

    //初始化容器
    this->initVector();
}

void printStudent(Student& s)
{
    cout << "学号：" << s.m_Id << " 姓名：" << s.m_Name << " 密码：" << s.m_Pwd << endl;
}
void printTeacher(Teacher& t)
{
    cout << "职工号： " << t.m_EmpId << " 姓名： " << t.m_Name << " 密码：" << t.m_Pwd << endl;
}

//查看账号
void Manager::showPerson()
{
    cout << "请选择查看的内容" << endl;
    cout << "1、查看所有的学生" << endl;
    cout << "2、查看所有的老师" << endl;

    int selcet = 0;
    cin >> selcet;

    if (selcet == 1)
    {
        //查看学生
        cout << "所有的学生信息如下：" << endl;
        for_each(vStu.begin(), vStu.end(), printStudent);
    }
    else if (selcet == 2)
    {
        //查看老师
        cout << "所有的老师信息如下：" << endl;
        for_each(vTea.begin(), vTea.end(), printTeacher);
    }

    system("pause");
    system("cls");
}

//查看机房信息
void Manager::showComputer()
{

    for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
    {
        cout << "机房ID号：" << it->m_ComId << " 机房最大容量：" << it->m_MaxNum << endl;
    }

    system("pause");
    system("cls");
}

//清空预约记录
void Manager::cleanFile()
{
    ofstream ofs(ORDER_FILE, ios::trunc);    //如果文件存在先删除，再创建
    ofs.close();

    cout << "清空成功！" << endl;
    system("pause");
    system("cls");
}

//初始化容器
void Manager::initVector()
{

    //读取学生信息   
    ifstream ifs;
    ifs.open(STUDENT_FILE, ios::in);
    if (!ifs.is_open())
    {
        cout << "文件读取失败" << endl;
        return;
    }

    //确保文件清空状态
    vStu.clear();
    vTea.clear();

    Student s;
    while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
    {
        vStu.push_back(s);
    }

    ifs.close();

    //读取老师信息
    ifs.open(TEACHER_FILE, ios::in);
    Teacher t;
    while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
    {
        vTea.push_back(t);
    }

    ifs.close();
}

//检测重复  参数1，检测的学号/职工号 参数2 检测类型
bool Manager::checkRepeat(int id, int type)
{
    if (type == 1)
    {
        //检测学生
        for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
        {
            if (id == it->m_Id)
            {
                return true;
            }
        }
    }
    else
    {
        //检测老师
        for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
        {
            if (id == it->m_EmpId)
            {
                return true;
            }
        }
    }

    return false;
}