#include <string>
using namespace std;

class Employee
{
public:
    Employee();
    Employee(const string &name);
    Employee(const Employee &) = delete;
    Employee &operator=(const Employee &) = delete;

    const int id() const { return id_; }

private:
    string name_;
    int id_;
    static int s_increment;
};