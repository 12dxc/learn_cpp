#include <string>
using namespace std;

// 定义一个使用引用计数的类
class HasPtr
{
public:
    // 构造函数分配新的string和新的计数器，将计数器置为1
    HasPtr(const string &s = string()) : ps(new string(s)), i(0), use(new size_t(1)) {}
    // 拷贝构造函数拷贝所有三个数据成员，并递增计数器
    HasPtr(const HasPtr &p) : ps(p.ps), i(p.i), use(p.use) { ++*use; }
    // 拷贝赋值需要同时完成拷贝构造和析构函数的工作
    HasPtr &operator=(const HasPtr &rhs)
    {
        ++*rhs.use;      // 递增右侧对象的引用计数
        if (--*use == 0) // 如果引用计数变为0
        {
            delete ps;  // 释放string内存
            delete use; // 释放计数器内存
        }
        // 将数据对象从rhs拷贝到本对象
        ps = rhs.ps;
        i = rhs.i;
        use = rhs.use;
        return *this; // 返回本对象
    }
    ~HasPtr()
    {
        if (--*use == 0) // 如果引用计数变为0
        {
            delete ps;  // 释放string内存
            delete use; // 释放计数器内存
        }
    }

private:
    string *ps;
    int i;
    size_t *use; // 用来记录有多少个对象共享*ps的成员
};