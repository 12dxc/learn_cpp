#include "screen.h"
#include <vector>

// 窗口管理类
class Window_mgr
{
public:
    // 窗口中每个屏幕的编号
    using ScreenIndex = vector<Screen>::size_type;

    Window_mgr() = default;
    // 按照编号将指定的Screen重置为空白
    void clear(ScreenIndex);

private:
    vector<Screen> screens{Screen(24, 80, ' ')}; // 类内初始值
};

void Window_mgr::clear(ScreenIndex i)
{
    // s是一个Screen的引用，指向我们想清空的那个屏幕
    Screen &s = screens[i];
    // 将那个选的Screen重置为空白
    s.contents = string(s.height * s.width, ' ');
}
