#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// ���ò����㷨  count  ͳ��Ԫ�ظ���

// 1��ͳ��������������
void test01()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(5);
    v.push_back(3);
    v.push_back(4);
    v.push_back(4);

    int num = count(v.begin(), v.end(), 4);
    cout << "4��Ԫ�ظ���Ϊ��" << num << endl;
}

// 2��ͳ���Զ�����������
class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    bool operator==(const Person &p)
    {
        if (this->m_Age == p.m_Age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    string m_Name;
    int m_Age;
};
void test02()
{
    vector<Person> v;

    Person p1("����", 35);
    Person p2("����", 35);
    Person p3("�ŷ�", 35);
    Person p4("����", 30);
    Person p5("�ܲ�", 25);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    Person p("�����", 35);

    int num = count(v.begin(), v.end(), p);

    cout << "�������ͬ�����" << num << "����" << endl;
}

int main()
{

    // test01();
    test02();

    system("pause");
    return 0;
}