#include<iostream>
using namespace std;
#include"speechManager.h"
#include<string>
#include<ctime>

int main()
{
    //随机数种子
    srand((unsigned int)time(NULL));
    //创建管理类对象
    SpeechManager sm;

    int choice = 0;   //用于存储用户的输入

    cout << "请输入您的选择：" << endl;
    while (true)
    {
        sm.show_Menu();

        cin >> choice;

        switch (choice)
        {
        case 1:      //开始比赛
            sm.startSpeech();
            break;
        case 2:      //查看往届比赛记录
            sm.showRecord();
            break;
        case 3:      //清空比赛记录
            sm.clearRecord();
            break;
        case 0:      //退出系统
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