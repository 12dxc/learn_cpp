#include <string>
using namespace std;

class Person
{
    // 成员数据
    string name;    // 姓名
    string address; // 地址
public:
    // 成员函数
    // 获取姓名
    string get_name() const
    {
        return this->name;
    }
    // 获取地址
    string get_address() const
    {
        return this->address;
    }
};
