#include <iostream>
#include <vector>
using namespace std;

// 函数对象类，对给定指针执行delete
class DebugDelete
{
public:
    DebugDelete(ostream &s = cerr) : os(s) {}
    // 与任何函数模板相同，T的类型由编译器推断
    template <typename T>
    void operator()(T *p) const
    {
        os << "正在删除 unique_ptr" << endl;
        delete p;
    }

private:
    ostream &os;
};

int main()
{
    double *p = new double;
    DebugDelete d;
    d(p);
    int *ip = new int;
    DebugDelete()(ip);

    return 0;
}
