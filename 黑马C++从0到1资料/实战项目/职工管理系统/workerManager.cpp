#include"workerManager.h"

WorkerManager::WorkerManager()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);  //���ļ�

    //1���ļ������ڵ����
    if (!ifs.is_open())
    {
        cout << "�ļ�������" << endl;

        //��ʼ������

        //��ʼ��������¼Ϊ0
        this->m_EmpNum = 0;
        //��ʼ������ָ��
        this->m_EmpArray = NULL;
        //��ʼ���ļ�Ϊ�ձ�־
        this->m_FileIsEmpty = true;
        ifs.close();
        return;

    }

    //2���ļ����ڵ�����Ϊ��
    char ch;
    ifs >> ch;   //ifs.eof()ֻ���ڳ��Զ�ȡ�ļ�������֮��Ż᷵��true����������Ҫ����ifs >> ch����ifs.get(ch)����ȡһ���ַ���Ȼ������ifs.eof()���ж��Ƿ񵽴����ļ�ĩβ��

    if (ifs.eof())
    {
        cout << "�ļ�Ϊ��" << endl;

        //��ʼ������

        //��ʼ��������¼Ϊ0
        this->m_EmpNum = 0;
        //��ʼ������ָ��
        this->m_EmpArray = NULL;
        //��ʼ���ļ�Ϊ�ձ�־
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }

    //3���ļ������ұ���ְ������
    int num = this->get_EmpNum();
    this->m_EmpNum = num;

    //���ٿռ�
    this->m_EmpArray = new Worker * [this->m_EmpNum];
    //���ļ��е����ݴ浽������
    this->init_Emp();
}

//ͳ������
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
        //ͳ�������ı�־
        num++;
    }

    ifs.close();

    return num;
}

//��ʼ��Ա��
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

        if (dId == 1) //��ְͨ��
        {
            worker = new Employee(id, name, dId);
        }
        else if (dId == 2)  //����
        {
            worker = new Manager(id, name, dId);
        }
        else    //�ϰ�
        {
            worker = new Boss(id, name, dId);
        }
        this->m_EmpArray[index] = worker;
        index++;
    }
    ifs.close();
}

//չʾ�˵�
void WorkerManager::Show_Menu()
{
    cout << "********************************************" << endl;
    cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
    cout << "*************  0.�˳��������  *************" << endl;
    cout << "*************  1.����ְ����Ϣ  *************" << endl;
    cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
    cout << "*************  3.ɾ����ְְ��  *************" << endl;
    cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
    cout << "*************  5.����ְ����Ϣ  *************" << endl;
    cout << "*************  6.���ձ������  *************" << endl;
    cout << "*************  7.��������ĵ�  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

//�˳�����
void WorkerManager::exitSystem()
{
    cout << "��ӭ�´�ʹ��" << endl;
    system("pause");
    exit(0);
}

//��ӹ���
void WorkerManager::Add_Emp()
{
    cout << "����������ְ�������� " << endl;
    int addNum = 0;
    cin >> addNum;

    if (addNum > 0)
    {
        //�����¿ռ��С
        int newSize = this->m_EmpNum + addNum;

        //�����¿ռ�
        Worker** newSpace = new Worker * [newSize];

        //��ԭ�ռ������ݴ�ŵ��¿ռ���
        if (this->m_EmpNum != NULL)
        {
            for (int i = 0; i < m_EmpNum; i++)
            {
                newSpace[i] = this->m_EmpArray[i];
            }
        }

        //����������
        for (int i = 0; i < addNum; i++)
        {
            int id;
            string name;
            int dSelect;

            cout << "������� " << i + 1 << " ����ְ����ţ�" << endl;
            cin >> id;


            cout << "������� " << i + 1 << " ����ְ��������" << endl;
            cin >> name;


            cout << "��ѡ���ְ���ĸ�λ��" << endl;
            cout << "1����ְͨ��" << endl;
            cout << "2������" << endl;
            cout << "3���ϰ�" << endl;
            cin >> dSelect;


            Worker* worker = NULL;
            switch (dSelect)
            {
            case 1: //��ͨԱ��
                worker = new Employee(id, name, 1);
                break;
            case 2: //����
                worker = new Manager(id, name, 2);
                break;
            case 3:  //�ϰ�
                worker = new Boss(id, name, 3);
                break;
            default:
                break;
            }
            newSpace[this->m_EmpNum + i] = worker;
        }
        //�ͷ�ԭ�пռ�
        delete[] this->m_EmpArray;
        //�����¿ռ��ָ��
        this->m_EmpArray = newSpace;
        //�����µĸ���
        this->m_EmpNum = newSize;
        //����ְ����Ϊ�յı�־
        this->m_FileIsEmpty = false;

        //��ʾ��Ϣ
        cout << "�ɹ����" << addNum << "����ְ��" << endl;
        this->save();
    }
    else
    {
        cout << "��������" << endl;
    }

    system("pause");
    system("cls");

}

//�����ļ�
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

//��ʾְ��
void WorkerManager::Show_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
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

//ɾ��ְ��
void WorkerManager::Del_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
    }
    else
    {
        //��ְ�����ɾ��
        cout << "��������Ҫɾ����ְ���ţ�" << endl;
        int id = 0;
        cin >> id;

        int index = this->IsExist(id);
        if (index != -1)   //˵��ְ�����ڣ�����Ҫɾ��indexλ���ϵ�ְ��
        {
            for (int i = index; i < this->m_EmpNum - 1; i++)  //m_EmpNum-1Ϊ�������һλ�±�
            {
                //����ǰ��
                this->m_EmpArray[i] == this->m_EmpArray[i + 1];
            }
            this->m_EmpNum--;  //���������м�¼����Ա����
            //����ͬ�����ļ���
            this->save();

            cout << "ɾ���ɹ�" << endl;
        }
        else
        {
            cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
        }
    }
    system("pause");
    system("cls");
}

//����ְ������ж�ְ���Ƿ����,�����ڷ���ְ����������λ�ã������ڷ���-1
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

//�޸�ְ��
void WorkerManager::Mod_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
    }
    else
    {
        cout << "�������޸�ְ���ı�ţ�" << endl;
        int id;
        cin >> id;

        int ret = this->IsExist(id);

        if (ret != -1)
        {
            //���ҵ���ŵ�ְ��

            delete this->m_EmpArray[ret];

            int newId = 0;
            string newName = "";
            int dSelect = 0;

            cout << "�鵽�� " << id << "��ְ������������ְ���ţ� " << endl;
            cin >> newId;
            cout << "�������������� " << endl;
            cin >> newName;
            cout << "�������λ�� " << endl;
            cout << "1����ְͨ��" << endl;
            cout << "2������" << endl;
            cout << "3���ϰ�" << endl;
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
            //�������ݵ�������
            this->m_EmpArray[ret] = worker;

            cout << "�޸ĳɹ�" << endl;

            //���������ݵ��ļ���
            this->save();
        }
        else
        {
            cout << "�޸�ʧ�ܣ�δ�鵽ְ����Ϣ" << endl;
        }
    }
    //������� ����
    system("pause");
    system("cls");
}

//����ְ��
void WorkerManager::Find_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
    }
    else
    {
        cout << "��������ҵķ�ʽ��" << endl;
        cout << "1����ְ����Ų���" << endl;
        cout << "2������������" << endl;

        int select = 0;
        cin >> select;

        if (select == 1)   //��ְ���Ų���
        {
            int id;
            cout << "������Ҫ���ҵ�ְ�����" << endl;
            cin >> id;
            int ret = IsExist(id);
            if (ret != -1)
            {
                cout << "�鵽��ְ����Ϣ����" << endl;
                this->m_EmpArray[ret]->showInfo();
            }
            else
            {
                cout << "����ʧ�ܣ����޴���" << endl;
            }
        }
        else if (select == 2)  //����������
        {
            string name;
            cout << "��������ҵ�������" << endl;
            cin >> name;

            //���ҵ��ı�־
            bool flag = false;
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                if (this->m_EmpArray[i]->m_Name == name)
                {
                    flag = true;
                    cout << "���ҳɹ���ְ�����Ϊ" <<
                        this->m_EmpArray[i]->m_Id <<
                        "����Ϣ���£�" << endl;
                    this->m_EmpArray[i]->showInfo();
                }
            }
            if (flag == false)
            {
                //���޴���
                cout << "����ʧ�ܣ����޴���" << endl;
            }

        }
        else
        {
            cout << "����ѡ������" << endl;
        }
    }
    system("pause");
    system("cls");
}

//����ְ��
void WorkerManager::Sort_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "��ѡ������ʽ�� " << endl;
        cout << "1����ְ���Ž�������" << endl;
        cout << "2����ְ���Ž��н���" << endl;

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
        cout << "����ɹ�,�������Ϊ��" << endl;
        this->save();
        this->Show_Emp();
    }
}

//����ļ�
void WorkerManager::Clean_File()
{
    cout << "ȷ����գ�" << endl;
    cout << "1��ȷ��" << endl;
    cout << "2������" << endl;

    int select = 0;
    cin >> select;


    if (select == 1)
    {   //������ļ��е�����
        ofstream ofs;
        //��ģʽ ios::trunc �������ɾ���ļ������´���
        ofs.open(FILENAME,ios::trunc); 
        ofs.close();

        //����ڳ����е�����
        //�������е�����ָ���Ƿ�Ϊ��
        if (this->m_EmpArray != NULL)
        {   //�����Ϊ�ս����е�ÿ�����������
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                if (this->m_EmpArray[i] != NULL)
                {
                    delete this->m_EmpArray[i];
                }
            }
            //��ʼ��������¼Ϊ0
            this->m_EmpNum = 0;
            //�ͷ���Ա����ռ�
            delete[] this->m_EmpArray;
            //��ʼ������ָ��
            this->m_EmpArray = NULL;
            //��ʼ���ļ�Ϊ�ձ�־
            this->m_FileIsEmpty = true;
        }
        cout << "��ճɹ�" << endl;
    }

    system("pause");
    system("cls");
}

WorkerManager::~WorkerManager()
{

}