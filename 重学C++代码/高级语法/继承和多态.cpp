#include <iostream>
using namespace std;

// 抽象图形类
class Shape
{
public:
    virtual double Area() = 0; // 子类方法实现不一致，需要加virtual
    virtual void Show() = 0;
    void SetColor(int color) { _color = color; }
    void Display()
    {
        cout << Area() << endl;
    }

private:
    int _color;
};
// 矩形类
class Square : public Shape
{
public:
    Square(int len) : _len(len) {}
    void Show() { cout << "Square" << endl; }
    double Area()
    {
        return _len * _len;
    }

private:
    double _len;
};
// 圆形类
class Circle : public Shape
{
public:
    Circle(double radius) : _radius(radius) {}
    void Show() { cout << "Circle" << endl; }
    double Area()
    {
        return 3.1415926 * _radius * _radius;
    }

private:
    double _radius;
};
// 三角形类
class Triangle : public Shape
{
public:
    Triangle(double len, double height) : _len(len), _height(height) {}
    void Show() { cout << "Triangle" << endl; }
    double Area()
    {
        return _len * _height / 2;
    }

private:
    double _len;
    double _height;
};

int main()
{
    // 面对变化，尽可能少修改原有的逻辑，要扩充逻辑
    const int shapeNum = 3; // 创建的图形数
    Square s1(2.0);
    s1.SetColor(1);
    Circle c1(2.0);
    Triangle t1(2.0, 3.0);

    Shape *shapes[shapeNum];
    shapes[0] = &s1;
    shapes[1] = &c1;
    shapes[2] = &t1;

    for (unsigned int i = 0; i < shapeNum; i++)
    {
        shapes[i]->Display();
    }

    system("pause");
    return 0;
}
