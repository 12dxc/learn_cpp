#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>

// ��5��ѡ�֣�ѡ��ABCDE��10����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷֣�ȥ����ί����ͷ֣�ȡƽ���֡�

// ѡ����
class Person
{
public:
    Person(string name, int sorece)
    {
        m_Name = name;
        m_Sorce = sorece;
    }

    string m_Name; // ����
    int m_Sorce;   // ƽ����
};

// ��ֵ
void createPerson(vector<Person> &v)
{
    string nameseed = "ABCDE";
    for (int i = 0; i < 5; i++)
    {
        string name = "ѡ��";
        name += nameseed[i];

        int score = 0;

        Person p(name, score);
        // ������Person������뵽������
        v.push_back(p);
    }
}

// ���
void setScore(vector<Person> &v)
{
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        // ����ί�ķ��� ���뵽deque����
        deque<int> d;
        for (int i = 0; i < 10; i++)
        {
            int score = rand() % 41 + 60; // 60~100
            d.push_back(score);
        }

        // ����
        sort(d.begin(), d.end());

        // ȥ����߷ֺ���ͷ�
        d.pop_back();
        d.pop_front();

        // ȡƽ����
        int sum = 0;
        for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
        {
            sum += *dit; // �ۼ�ÿ����ί�ķ���
        }

        int avg = sum / d.size();

        // ��ƽ���ָ�ֵ��ѡ������
        it->m_Sorce = avg;
    }
}

// ��ӡ
void showScore(vector<Person> &v)
{
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "������" << it->m_Name << " ƽ����" << it->m_Sorce << endl;
    }
}

int main()
{
    // ���������
    srand((unsigned int)time(NULL));

    // 1����������ѡ��
    vector<Person> v; // ���ѡ�ֵ�����
    createPerson(v);

    // 2����5λѡ�ִ��
    setScore(v);

    // 3����ʾ���÷�
    showScore(v);

    system("pause");
    return 0;
}