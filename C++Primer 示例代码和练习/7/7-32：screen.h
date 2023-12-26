#include <iostream>
#include <string>
using namespace std;

// 窗口类
class Screen
{
public:
    typedef string::size_type pos;
    // Window_magr的成员可以访问Screen类的私有部分
    friend class Window_mgr;

    // 构造函数
    Screen() = default;
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}

    // 读取光标处的字符
    char get() const // 隐式内联
    {
        return contents[cursor];
    }
    // 读取指定位置的字符
    inline char get(pos r, pos c) const // 显式内联
    {
        return contents[r * width + c];
    }
    Screen &move(pos r, pos c); // 能在之后被设为内联

    // 设置成员函数contents
    Screen &set(char);
    Screen &set(pos, pos, char);

    // 打印屏幕的内容
    const Screen &display(ostream &os) const
    {
        do_display(os);
        return *this;
    };
    Screen &display(ostream &os)
    {
        do_display(os);
        return *this;
    };

private:
    // 该函数负责显示Screen的内容
    void do_display(ostream &os) const {os << contents;}
    pos cursor = 0;            // 光标的位置
    pos height = 0, width = 0; // 屏幕宽高
    string contents;            // Screen的内容
};

inline Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}
// 使用引用才能改变值，而非副本
Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}
Screen &Screen::set(pos r, pos c, char ch)
{
    contents[r * width + c] = ch;
    return *this;
}