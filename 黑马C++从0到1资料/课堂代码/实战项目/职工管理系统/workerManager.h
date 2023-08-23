#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include"boss.h"
#include"employee.h"
#include"manager.h"
#include <fstream>
#define  FILENAME "empFile.txt"

class WorkerManager
{
public:
    WorkerManager();

    //չʾ�˵�
    void Show_Menu();

    //�˳�����
    void exitSystem();

    //��¼�ļ��е���������
    int m_EmpNum;

    //Ա�������ָ��
    Worker** m_EmpArray;

    //����ְ��
    void Add_Emp();

    //�����ļ�
    void save();

    //��־�ļ��Ƿ�Ϊ��
    bool m_FileIsEmpty;

    //ͳ������
    int get_EmpNum();

    //��ʼ��Ա��
    void init_Emp();

    //��ʾְ��
    void Show_Emp();

    //ɾ��ְ��
    void Del_Emp();

    //����ְ������ж�ְ���Ƿ����,�����ڷ���ְ����������λ�ã������ڷ���-1
    int IsExist(int id);

    //�޸�ְ��
    void Mod_Emp();

    //����ְ��
    void Find_Emp();

    //����ְ��
    void Sort_Emp();

    //����ļ�
    void Clean_File();

    ~WorkerManager();

private:

};
