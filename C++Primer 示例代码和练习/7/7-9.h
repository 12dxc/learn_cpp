#include <string>
#include <iostream>
using namespace std;

struct Person
{
    // ��Ա����
    string name;    // ����
    string address; // ��ַ

    // ��Ա����
    // ��ȡ����
    string const &get_name() const
    {
        return this->name;
    }
    // ��ȡ��ַ
    string const &get_address() const
    {
        return this->address;
    }
};

// ������ص����⺯��
// ��ȡ��Ϣ
istream &read(istream &is, Person &p)
{
    return is >> p.name >> p.address;
}
// ��ӡ��Ϣ
ostream &print(ostream &os, Person &p)
{
    return os << p.get_name() << " " << p.get_address() << endl;
}