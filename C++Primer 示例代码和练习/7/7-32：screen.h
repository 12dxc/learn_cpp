#include <iostream>
#include <string>
using namespace std;

// ������
class Screen
{
public:
    typedef string::size_type pos;
    // Window_magr�ĳ�Ա���Է���Screen���˽�в���
    friend class Window_mgr;

    // ���캯��
    Screen() = default;
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}

    // ��ȡ��괦���ַ�
    char get() const // ��ʽ����
    {
        return contents[cursor];
    }
    // ��ȡָ��λ�õ��ַ�
    inline char get(pos r, pos c) const // ��ʽ����
    {
        return contents[r * width + c];
    }
    Screen &move(pos r, pos c); // ����֮����Ϊ����

    // ���ó�Ա����contents
    Screen &set(char);
    Screen &set(pos, pos, char);

    // ��ӡ��Ļ������
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
    // �ú���������ʾScreen������
    void do_display(ostream &os) const {os << contents;}
    pos cursor = 0;            // ����λ��
    pos height = 0, width = 0; // ��Ļ���
    string contents;            // Screen������
};

inline Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}
// ʹ�����ò��ܸı�ֵ�����Ǹ���
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