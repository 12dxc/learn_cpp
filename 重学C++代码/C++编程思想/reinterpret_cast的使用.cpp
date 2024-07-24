#include <iostream>
using namespace std;

int Test()
{
    return 0;
}

int main()
{
    // C++ reinterpret_cast  重解释类型转换: 很危险
    // 重新解释类型，既不检查指向的内容，也不检查指针类型本身；
    // 但要求转换前后的类型所占用内存大小一致，否则引发异常

    typedef void (*FuncPtr)();
    FuncPtr funcPtr;
    // funcPtr = &Test;   错误，左值是void* 而右值是int
    funcPtr = reinterpret_cast<FuncPtr>(&Test);

    system("pause");
    return 0;
}