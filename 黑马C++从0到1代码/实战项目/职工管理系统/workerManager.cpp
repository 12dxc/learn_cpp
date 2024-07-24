#include"workerManager.h"

WorkerManager::WorkerManager()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);  //读文件

    //1、文件不存在的情况
    if (!ifs.is_open())
    {
        cout << "文件不存在" << endl;

        //初始化属性

        //初始化人数记录为0
        this->m_EmpNum = 0;
        //初始化数组指针
        this->m_EmpArray = NULL;
        //初始化文件为空标志
        this->m_FileIsEmpty = true;
        ifs.close();
        return;

    }

    //2、文件存在但数据为空
    char ch;
    ifs >> ch;   //ifs.eof()只有在尝试读取文件结束符之后才会返回true，所以你需要先用ifs >> ch或者ifs.get(ch)来读取一个字符，然后再用ifs.eof()来判断是否到达了文件末尾。

    if (ifs.eof())
    {
        cout << "文件为空" << endl;

        //初始化属性

        //初始化人数记录为0
        this->m_EmpNum = 0;
        //初始化数组指针
        this->m_EmpArray = NULL;
        //初始化文件为空标志
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }

    //3、文件存在且保存职工数据
    int num = this->get_EmpNum();
    this->m_EmpNum = num;

    //开辟空间
    this->m_EmpArray = new Worker * [this->m_EmpNum];
    //将文件中的数据存到数组中
    this->init_Emp();
}

//统计人数
int WorkerManager::get_EmpNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);


    int id;
    string name;
    int dId;

    int num = 0;

    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        //统计人数的标志
        num++;
    }

    ifs.close();

    return num;
}

//初始化员工
void WorkerManager::init_Emp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        Worker* worker = NULL;

        if (dId == 1) //普通职工
        {
            worker = new Employee(id, name, dId);
        }
        else if (dId == 2)  //经理
        {
            worker = new Manager(id, name, dId);
        }
        else    //老板
        {
            worker = new Boss(id, name, dId);
        }
        this->m_EmpArray[index] = worker;
        index++;
    }
    ifs.close();
}

//展示菜单
void WorkerManager::Show_Menu()
{
    cout << "********************************************" << endl;
    cout << "*********  欢迎使用职工管理系统！ **********" << endl;
    cout << "*************  0.退出管理程序  *************" << endl;
    cout << "*************  1.增加职工信息  *************" << endl;
    cout << "*************  2.显示职工信息  *************" << endl;
    cout << "*************  3.删除离职职工  *************" << endl;
    cout << "*************  4.修改职工信息  *************" << endl;
    cout << "*************  5.查找职工信息  *************" << endl;
    cout << "*************  6.按照编号排序  *************" << endl;
    cout << "*************  7.清空所有文档  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

//退出功能
void WorkerManager::exitSystem()
{
    cout << "欢迎下次使用" << endl;
    system("pause");
    exit(0);
}

//添加功能
void WorkerManager::Add_Emp()
{
    cout << "请输入增加职工数量： " << endl;
    int addNum = 0;
    cin >> addNum;

    if (addNum > 0)
    {
        //计算新空间大小
        int newSize = this->m_EmpNum + addNum;

        //开辟新空间
        Worker** newSpace = new Worker * [newSize];

        //将原空间下内容存放到新空间下
        if (this->m_EmpNum != NULL)
        {
            for (int i = 0; i < m_EmpNum; i++)
            {
                newSpace[i] = this->m_EmpArray[i];
            }
        }

        //输入新数据
        for (int i = 0; i < addNum; i++)
        {
            int id;
            string name;
            int dSelect;

            cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
            cin >> id;


            cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
            cin >> name;


            cout << "请选择该职工的岗位：" << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cin >> dSelect;


            Worker* worker = NULL;
            switch (dSelect)
            {
            case 1: //普通员工
                worker = new Employee(id, name, 1);
                break;
            case 2: //经理
                worker = new Manager(id, name, 2);
                break;
            case 3:  //老板
                worker = new Boss(id, name, 3);
                break;
            default:
                break;
            }
            newSpace[this->m_EmpNum + i] = worker;
        }
        //释放原有空间
        delete[] this->m_EmpArray;
        //更改新空间的指向
        this->m_EmpArray = newSpace;
        //更新新的个数
        this->m_EmpNum = newSize;
        //更新职工不为空的标志
        this->m_FileIsEmpty = false;

        //提示信息
        cout << "成功添加" << addNum << "名新职工" << endl;
        this->save();
    }
    else
    {
        cout << "输入有误" << endl;
    }

    system("pause");
    system("cls");

}

//保存文件
void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out);
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        ofs << this->m_EmpArray[i]->m_Id << " "
            << this->m_EmpArray[i]->m_Name << " "
            << this->m_EmpArray[i]->m_DeptId << endl;
    }
    ofs.close();
}

//显示职工
void WorkerManager::Show_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
    }
    else
    {
        for (int i = 0; i < this->m_EmpNum; i++)
        {
            this->m_EmpArray[i]->showInfo();
        }
    }

    system("pause");
    system("cls");
}

//删除职工
void WorkerManager::Del_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
    }
    else
    {
        //按职工编号删除
        cout << "请输入想要删除的职工号：" << endl;
        int id = 0;
        cin >> id;

        int index = this->IsExist(id);
        if (index != -1)   //说明职工存在，并且要删除index位置上的职工
        {
            for (int i = index; i < this->m_EmpNum - 1; i++)  //m_EmpNum-1为数组最后一位下标
            {
                //数据前移
                this->m_EmpArray[i] == this->m_EmpArray[i + 1];
            }
            this->m_EmpNum--;  //更新数组中记录的人员个数
            //数据同步到文件中
            this->save();

            cout << "删除成功" << endl;
        }
        else
        {
            cout << "删除失败，未找到该职工" << endl;
        }
    }
    system("pause");
    system("cls");
}

//按照职工编号判断职工是否存在,若存在返回职工在数组中位置，不存在返回-1
int WorkerManager::IsExist(int id)
{
    int index = -1;
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        if (this->m_EmpArray[i]->m_Id == id)
        {
            index = i;
            break;
        }
    }
    return index;
}

//修改职工
void WorkerManager::Mod_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
    }
    else
    {
        cout << "请输入修改职工的编号：" << endl;
        int id;
        cin >> id;

        int ret = this->IsExist(id);

        if (ret != -1)
        {
            //查找到编号的职工

            delete this->m_EmpArray[ret];

            int newId = 0;
            string newName = "";
            int dSelect = 0;

            cout << "查到： " << id << "号职工，请输入新职工号： " << endl;
            cin >> newId;
            cout << "请输入新姓名： " << endl;
            cin >> newName;
            cout << "请输入岗位： " << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cin >> dSelect;

            Worker* worker = NULL;
            switch (dSelect)
            {
            case 1:
                worker = new Employee(newId, newName, dSelect);
                break;

            case 2:
                worker = new Manager(newId, newName, dSelect);
                break;
            case 3:
                worker = new Boss(newId, newName, dSelect);
                break;
            default:
                break;
            }
            //更新数据到数组中
            this->m_EmpArray[ret] = worker;

            cout << "修改成功" << endl;

            //保存新数据到文件中
            this->save();
        }
        else
        {
            cout << "修改失败，未查到职工信息" << endl;
        }
    }
    //按任意键 清屏
    system("pause");
    system("cls");
}

//查找职工
void WorkerManager::Find_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
    }
    else
    {
        cout << "请输入查找的方式：" << endl;
        cout << "1、按职工编号查找" << endl;
        cout << "2、按姓名查找" << endl;

        int select = 0;
        cin >> select;

        if (select == 1)   //按职工号查找
        {
            int id;
            cout << "请输入要查找的职工编号" << endl;
            cin >> id;
            int ret = IsExist(id);
            if (ret != -1)
            {
                cout << "查到该职工信息如下" << endl;
                this->m_EmpArray[ret]->showInfo();
            }
            else
            {
                cout << "查找失败，查无此人" << endl;
            }
        }
        else if (select == 2)  //按姓名查找
        {
            string name;
            cout << "请输入查找的姓名：" << endl;
            cin >> name;

            //查找到的标志
            bool flag = false;
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                if (this->m_EmpArray[i]->m_Name == name)
                {
                    flag = true;
                    cout << "查找成功，职工编号为" <<
                        this->m_EmpArray[i]->m_Id <<
                        "的信息如下：" << endl;
                    this->m_EmpArray[i]->showInfo();
                }
            }
            if (flag == false)
            {
                //查无此人
                cout << "查找失败，查无此人" << endl;
            }

        }
        else
        {
            cout << "输入选项有误" << endl;
        }
    }
    system("pause");
    system("cls");
}

//排序职工
void WorkerManager::Sort_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "请选择排序方式： " << endl;
        cout << "1、按职工号进行升序" << endl;
        cout << "2、按职工号进行降序" << endl;

        int selcet = 0;
        cin >> selcet;
        if (selcet == 1)
        {
            for (int i = 0; i < this->m_EmpNum - 1; i++)
            {
                for (int j = 0; j < m_EmpNum - 1 - i; j++)
                {
                    if (this->m_EmpArray[j]->m_Id > this->m_EmpArray[j + 1]->m_Id)
                    {
                        Worker* temp = this->m_EmpArray[j];
                        this->m_EmpArray[j] = this->m_EmpArray[j + 1];
                        this->m_EmpArray[j + 1] = temp;
                    }
                }
            }

        }
        else
        {
            for (int i = 0; i < this->m_EmpNum - 1; i++)
            {
                for (int j = 0; j < m_EmpNum - 1 - i; j++)
                {
                    if (this->m_EmpArray[j]->m_Id < this->m_EmpArray[j + 1]->m_Id)
                    {
                        Worker* temp = this->m_EmpArray[j];
                        this->m_EmpArray[j] = this->m_EmpArray[j + 1];
                        this->m_EmpArray[j + 1] = temp;
                    }
                }
            }
        }
        cout << "排序成功,排序后结果为：" << endl;
        this->save();
        this->Show_Emp();
    }
}

//清空文件
void WorkerManager::Clean_File()
{
    cout << "确认清空？" << endl;
    cout << "1、确认" << endl;
    cout << "2、返回" << endl;

    int select = 0;
    cin >> select;


    if (select == 1)
    {   //清空在文件中的数据
        ofstream ofs;
        //打开模式 ios::trunc 如果存在删除文件并重新创建
        ofs.open(FILENAME,ios::trunc); 
        ofs.close();

        //清空在程序中的数据
        //检测程序中的数组指针是否为空
        if (this->m_EmpArray != NULL)
        {   //如果不为空将其中的每个对象再清空
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                if (this->m_EmpArray[i] != NULL)
                {
                    delete this->m_EmpArray[i];
                }
            }
            //初始化人数记录为0
            this->m_EmpNum = 0;
            //释放人员数组空间
            delete[] this->m_EmpArray;
            //初始化数组指针
            this->m_EmpArray = NULL;
            //初始化文件为空标志
            this->m_FileIsEmpty = true;
        }
        cout << "清空成功" << endl;
    }

    system("pause");
    system("cls");
}

WorkerManager::~WorkerManager()
{

}