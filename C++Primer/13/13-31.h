#include <string>
#include <iostream>
using namespace std;

// 定义一个使用引用计数的类
class HasPtr
{
public:
    friend void swap(HasPtr &, HasPtr &); // 交换函数

    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i) {}
    HasPtr &operator=(const HasPtr &hp)
    {
        auto new_p = new std::string(*hp.ps);
        delete ps;
        ps = new_p;
        i = hp.i;
        return *this;
    }
    bool operator<(HasPtr &rhs)
    {
        return *ps > *rhs.ps;
    }
    ~HasPtr()
    {
        delete ps;
    }
    void show() { cout << *ps << endl; }

private:
    string *ps;
    int i;
};

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    cout << "从函数完成了对lhs，rhs的交换" << endl;
}