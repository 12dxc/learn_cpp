#include <iostream>
#include <string>
using namespace std;

// 窗口类
class Screen
{
public:
    typedef string::size_type pos;

    // 构造函数
    Screen() = default;
    Screen(pos ht, pos wd) : height(ht), width(wd), content(ht * wd, ' ') {}
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), content(ht * wd, c) {}

    // 读取光标处的字符
    char get() const // 隐式内联
    {
        return content[cursor];
    }
    // 读取指定位置的字符
    inline char get(pos r, pos c) const // 显式内联
    {
        return content[r * width + c];
    }
    Screen &move(pos r, pos c); // 能在之后被设为内联

private:
    pos cursor = 0;            // 光标的位置
    pos height = 0, width = 0; // 屏幕宽高
    string content;            // Screen的内容
};

inline Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}
