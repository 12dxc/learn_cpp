#pragma once
#include <iostream>
using namespace std;
class Complex
{
public:
    Complex();
    Complex(double r, double i); // 构造函数
    // 拷贝构造
    Complex(const Complex &x);

    // 查看实部
    double getReal() const; // const修饰的是函数体，表示在函数体内部不可变
    // 修改实部
    void setReal(double d);
    // 查看虚部
    double getImage() const;
    // 修改虚部
    void setImage(double r);

    // 运算符重载
    Complex operator+(const Complex &x);
    Complex &operator=(const Complex &x);
    // 前置++
    Complex &operator++();
    // 后置++
    Complex operator++(int);
    // 前置--
    Complex &operator--();
    // 后置--
    Complex operator--(int);
    // 移位运算符<<
    friend ostream &operator<<(ostream &os, const Complex &x);
    // 移位运算符<<
    friend istream &operator>>(istream &is, Complex &x);
    //+=运算符
    Complex &operator+=(Complex &x);
    //比较运算符==
    bool operator==(const Complex&x);
    //比较运算符!=
    bool operator!=(const Complex&x);


    virtual ~Complex(); // 虚析构函数
private:
    double _real;  // 复数的实部
    double _image; // 复数的虚部
};
