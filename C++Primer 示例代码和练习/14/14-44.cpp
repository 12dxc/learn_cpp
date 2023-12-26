#include <iostream>
#include <map>
#include <functional>
#include <string>
using namespace std;

// 加法
int add(int i, int j) { return i + j; }
// 取余
auto mod = [](int i, int j)
{ return i % j; };
// 除法
struct divide
{
    int operator()(int i, int j) { return i / j; }
};

int main()
{
    map<string, function<int(int, int)>> binops = {
        {"+", add},          // 函数指针
        {"-", minus<int>()}, // 标准库函数对象
        {"/", divide()},     // 函数对象
        {"*", [](int i, int j)
         { return i * j; }}, // lambda
        {"%", mod}};         // lambda
    cout << binops["+"](10, 5) << endl;
    cout << binops["-"](10, 5) << endl;
    cout << binops["/"](10, 5) << endl;
    cout << binops["*"](10, 5) << endl;
    cout << binops["%"](10, 5) << endl;

    system("pause");
    return 0;
}