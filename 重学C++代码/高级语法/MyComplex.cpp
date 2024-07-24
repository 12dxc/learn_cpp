#include "MyComplex.h"

// 构造函数
Complex::Complex()
{
    this->_real = 0.0;
    this->_image = 0.0;
}
// 有参构造
Complex::Complex(double r, double i)
{
    this->_real = r;
    this->_image = i;
}
// 拷贝构造
Complex::Complex(const Complex &x)
{
    _real = x._real;
    _image = x._image;
}

// 查看实部
double Complex::getReal() const
{
    return _real;
}
// 修改实部
void Complex::setReal(double d)
{
    _real = d;
}
// 查看虚部
double Complex::getImage() const
{
    return _image;
}
// 修改虚部
void Complex::setImage(double r)
{
    _image = r;
}

// 运算符重载
Complex Complex::operator+(const Complex &x)
{
    /*Complex temp;
    temp._real = this->_real + x._real;
    temp._image = this->_image + x._image;
    return temp;*/

    // 临时对象的优化
    return Complex(_real + x._real, _image + x._image);
}

Complex &Complex::operator=(const Complex &x) // 返回引用不会产生拷贝构造
{
    if(this == &x)
	{
	return*this;
	}
    this->_real = x._real;
    this->_image = x._image;

    return *this;
}

// 前置++
Complex &Complex::operator++()
{
    _real++;
    _image++;
    return *this;
}
// 后置++
Complex Complex::operator++(int)
{
    /*Complex tmp(*this);
    _real++;
    _image++;
    return tmp;*/

    return Complex(_real++, _image++);
}

// 前置--
Complex &Complex::operator--()
{
    _real--;
    _image--;
    return *this;
}
// 后置--
Complex Complex::operator--(int)
{

    return Complex(_real--, _image--);
}

// 移位运算符<<
ostream &operator<<(ostream &os, const Complex &x)
{
    os << "实部的值：" << x._real << "虚部的值：" << x._image;
    return os;
}
// 移位运算符<<
istream &operator>>(istream &is, Complex &x)
{
    is >> x._real >> x._image;
    return is;
}

//+=运算符
Complex &Complex::operator+=(Complex &x)
{
    _real += x._real;
    _image += x._image;

    return *this;
}
// 比较运算符==
bool Complex::operator==(const Complex &x)
{
    return (_real == x._real) && (_image == x._image);
}
// 比较运算符!=
bool Complex::operator!=(const Complex &x)
{
    return (_real != x._real) && (_image != x._image);
}

Complex::~Complex()
{
}