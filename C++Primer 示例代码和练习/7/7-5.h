#include <string>
using namespace std;

class Person
{
    // ��Ա����
    string name;    // ����
    string address; // ��ַ
public:
    // ��Ա����
    // ��ȡ����
    string get_name() const
    {
        return this->name;
    }
    // ��ȡ��ַ
    string get_address() const
    {
        return this->address;
    }
};
