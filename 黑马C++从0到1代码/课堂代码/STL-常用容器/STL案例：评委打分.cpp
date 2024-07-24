#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>

// 有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。

// 选手类
class Person
{
public:
    Person(string name, int sorece)
    {
        m_Name = name;
        m_Sorce = sorece;
    }

    string m_Name; // 姓名
    int m_Sorce;   // 平均分
};

// 赋值
void createPerson(vector<Person> &v)
{
    string nameseed = "ABCDE";
    for (int i = 0; i < 5; i++)
    {
        string name = "选手";
        name += nameseed[i];

        int score = 0;

        Person p(name, score);
        // 将创建Person对象放入到容器中
        v.push_back(p);
    }
}

// 打分
void setScore(vector<Person> &v)
{
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        // 奖评委的分数 放入到deque容器
        deque<int> d;
        for (int i = 0; i < 10; i++)
        {
            int score = rand() % 41 + 60; // 60~100
            d.push_back(score);
        }

        // 排序
        sort(d.begin(), d.end());

        // 去除最高分和最低分
        d.pop_back();
        d.pop_front();

        // 取平均分
        int sum = 0;
        for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
        {
            sum += *dit; // 累加每个评委的分数
        }

        int avg = sum / d.size();

        // 将平均分赋值给选手身上
        it->m_Sorce = avg;
    }
}

// 打印
void showScore(vector<Person> &v)
{
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "姓名：" << it->m_Name << " 平均分" << it->m_Sorce << endl;
    }
}

int main()
{
    // 随机数种子
    srand((unsigned int)time(NULL));

    // 1、创建五名选手
    vector<Person> v; // 存放选手的容器
    createPerson(v);

    // 2、给5位选手打分
    setScore(v);

    // 3、显示最后得分
    showScore(v);

    system("pause");
    return 0;
}