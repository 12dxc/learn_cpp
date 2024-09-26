#include <iostream>
#include <functional>
using namespace std;

// 实现一元谓词绑定器
template <typename Compare, typename T>
class _mybind1st
{
public:
    _mybind1st(Compare comp, const T &val) : comp_(comp), val_(val) {}
    bool operator()(const T &second)
    {
        return comp_(val_, second);
    }

private:
    Compare comp_;
    T val_;
};

// 实现bing1st() 绑定器，返回函数对象
template <typename Compare, typename T>
_mybind1st<Compare, T> mybind1st(Compare comp, const T &val)
{
    return _mybind1st<Compare, T>(comp, val);
};

int main()
{
    cout << mybind1st(less<int>(), 20)(30) << endl;

    return 0;
}
