#include <string>
#include <iostream>
using namespace std;

struct Person
{
    // 成员数据
    string name;    // 姓名
    string address; // 地址

    // 成员函数
    // 获取姓名
    string const &get_name() const
    {
        return this->name;
    }
    // 获取地址
    string const &get_address() const
    {
        return this->address;
    }
};

// 与类相关的类外函数
// 读取信息
istream &read(istream &is, Person &p)
{
    return is >> p.name >> p.address;
}
// 打印信息
ostream &print(ostream &os, Person &p)
{
    return os << p.get_name() << " " << p.get_address() << endl;
}