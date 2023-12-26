#include <string>
using namespace std;

class Employee
{
public:
    Employee()
    {
        id = s_increment++;
    }
    Employee(const string &name)
    {
        m_name = name;
        id = s_increment++;
    }

private:
    string m_name; // 雇员姓名
    string id;     // 唯一雇员证号
    static int s_increment;
};
int Employee::s_increment = 0;
