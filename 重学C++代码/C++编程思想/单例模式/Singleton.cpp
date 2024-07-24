#include "Singleton.h"

Singleton* Singleton::This = nullptr;
const Singleton* Singleton::getinstance()
{
    //判断系统是否已经有这个单例，如果有则返回，如果没有则创建
    if (!This)
    {
        This = new Singleton;
    }
    return This;
}

Singleton::Singleton()
{

}
Singleton::~Singleton()
{

}