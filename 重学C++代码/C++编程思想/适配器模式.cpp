#include<iostream>
#include<string>
using namespace std;

class LegacyRectangle
{
public:
    LegacyRectangle(double x1, double y1, double x2, double y2)
    {
        _x1 = x1;
        _y1 = y1;
        _x2 = x2;
        _y2 = y2;
    }

    void LegacyDraw()
    {
        cout << "LegacyRectangle::LegacyDraw()" << _x1 << " " << _y1 << " " << _x2 << " " << _y2 << endl;
    }

private:
    double _x1;
    double _y1;
    double _x2;
    double _y2;
};

class Rectangle
{
public:
    virtual void Draw(string str) = 0;

};

//第一种适配的方式：使用多重继承
class RectangleAdapter :public Rectangle, public LegacyRectangle
{
public:
    RectangleAdapter(double x, double y, double w, double h) :
        LegacyRectangle(x, y, x + w, y + h)
    {
        cout << "RectangleAdapter(int x, int y, int w, int h)" << endl;
    }
    virtual void Draw(string str)
    {
        cout << "RectangleAdapter::Draw()" << endl;
        LegacyDraw();
    }
};

//第二种适配的方式：组合方式
class RectangleAdapter2 :public Rectangle
{
public:
    RectangleAdapter2(double x, double y, double w, double h) :
        _lRect(x, y, x + w, y + h)
    {
        cout << "RectangleAdapter(int x, int y, int w, int h)" << endl;
    }
    virtual void Draw(string str)
    {
        cout << "RectangleAdapter::Draw()" << endl;
        _lRect;
    }
private:
    LegacyRectangle _lRect;
};

int main()
{
    double x = 20.0, y = 50.0, w = 300.0, h = 200.0;
    RectangleAdapter ra(x, y, w, h);
    Rectangle* pR = &ra;
    pR->Draw("写 Adapter");

    cout << endl;
    RectangleAdapter2 ra2(x, y, w, h);
    Rectangle* pR2 = &ra2;
    pR2->Draw("写 Adapter2");

    system("pause");
    return 0;
}