#include<iostream>
using namespace std;
#include"speechManager.h"
#include<string>
#include<ctime>

int main()
{
    //���������
    srand((unsigned int)time(NULL));
    //�������������
    SpeechManager sm;

    int choice = 0;   //���ڴ洢�û�������

    cout << "����������ѡ��" << endl;
    while (true)
    {
        sm.show_Menu();

        cin >> choice;

        switch (choice)
        {
        case 1:      //��ʼ����
            sm.startSpeech();
            break;
        case 2:      //�鿴���������¼
            sm.showRecord();
            break;
        case 3:      //��ձ�����¼
            sm.clearRecord();
            break;
        case 0:      //�˳�ϵͳ
            sm.exitSystem();
            break;
        default:
            system("cls");
            break;
        }
    }


    system("pause");
    return 0;
}