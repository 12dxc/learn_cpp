#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include"speaker.h"
#include<map>
#include<algorithm>
#include<deque>
#include<functional>
#include<numeric>
#include<fstream>


//����ݽ�����������
class SpeechManager
{
public:

    //���캯��
    SpeechManager();

    //��ʾ�˵�
    void show_Menu(); 

    //�˳�ϵͳ
    void exitSystem();

    //��������
    ~SpeechManager();

    //��ʼ������
    void initSpeech();

    //����12��ѡ��
    void createSpeaker();

    //��ʼ����  �������̿��ƺ���
    void startSpeech();

    //��ǩ
    void speechDraw();   

    //����
    void speechContest();

    //��ʾ�÷�
    void showScore();

    //�����¼
    void saveRecord();

    //��ȡ��¼
    void loadRecord();

    //�ж��ļ��Ƿ�Ϊ��
    bool fileIsEmpty;

    //��������¼������
    map<int, vector<string>>m_Record;
    
    //��ʾ����÷�
    void showRecord();

    //��ռ�¼
    void clearRecord();


    //��Ա����
    //�����һ��ѡ�ֱ�ŵ�����
    vector<int>v1;

    //��һ�ֽ�����ѡ�ֱ������
    vector<int>v2;

    //ʤ��ǰ����ѡ�ֱ������
    vector<int>vVictory;

    //��ű���Լ���Ӧ����ѡ������
    map<int, Speaker>m_Speaker;

    //��¼��������
    int m_Index;
};