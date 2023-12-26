#include <iostream>
#include <string>
using namespace std;

// ������
class Screen
{
public:
    typedef string::size_type pos;

    // ���캯��
    Screen() = default;
    Screen(pos ht, pos wd) : height(ht), width(wd), content(ht * wd, ' ') {}
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), content(ht * wd, c) {}

    // ��ȡ��괦���ַ�
    char get() const // ��ʽ����
    {
        return content[cursor];
    }
    // ��ȡָ��λ�õ��ַ�
    inline char get(pos r, pos c) const // ��ʽ����
    {
        return content[r * width + c];
    }
    Screen &move(pos r, pos c); // ����֮����Ϊ����

private:
    pos cursor = 0;            // ����λ��
    pos height = 0, width = 0; // ��Ļ���
    string content;            // Screen������
};

inline Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}
