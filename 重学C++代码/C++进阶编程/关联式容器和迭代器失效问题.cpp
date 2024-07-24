#include<iostream>
#include<map>
#include<set>
#include<string>
#include<algorithm>
using namespace std;

struct Display
{
    void operator()(pair < string, double>info)
    {
        cout << info.first << ":" << info.second << endl;
    }
};



int main()
{
    map<string, double> studentSocres;
    //三种插入方法
    studentSocres["李明"] = 95.0;
    studentSocres["李红"] = 98.5;
    studentSocres.insert(pair<string, double>("张三", 100.0));
    studentSocres.insert(pair<string, double>("李四", 94.5));
    studentSocres.insert(map<string, double>::value_type("王五", 94.5));

    //修改指定key的值
    studentSocres["王五"] = 88;

    //遍历输出map容器
    for_each(studentSocres.begin(), studentSocres.end(), Display());
    cout << endl;
    map<string, double>::iterator it;
    //查询指定key的值
    it = studentSocres.find("王五");
    if (it != studentSocres.end())
    {
        cout << "查找的人的分数是:" << it->second << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }

    //使用迭代器完成遍历查找的过程
    it = studentSocres.begin();
    //第一种方式  while循环
    while (it != studentSocres.end())
    {
        if (it->second < 95.0)
        {
            studentSocres.erase(it++);   //删除时要让迭代器指向下一个值
        }
        else
        {
            it++;
        }
    }
    cout << "高于95的人:" << endl;
    for_each(studentSocres.begin(), studentSocres.end(), Display());
    cout << endl;
    //第二种方式  for循环
    for (it = studentSocres.begin(); it != studentSocres.end(); it++)
    {
        if (it->second < 98)
        {
            it = studentSocres.erase(it);  //迭代器会返回下一个值的指针，所以需要接收
        }
    }
    cout << "高于98的人:" << endl;
    for_each(studentSocres.begin(), studentSocres.end(), Display());
    cout << endl;

    //查找并删除元素
    it = studentSocres.find("李红");
    studentSocres.erase(it);
    for_each(studentSocres.begin(), studentSocres.end(), Display());
    cout << endl;

    //如果知道key,可直接用erase() 删除,参数为key
    studentSocres.erase("张三");  //返回1删除成功，返回0未删除成功

    //删除全部元素 也可以用erase() 参数为一个区间
    studentSocres.erase(studentSocres.begin(), studentSocres.end());

    system("pause");
    return 0;
}