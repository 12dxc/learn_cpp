#ifndef Any_H
#define Any_H

#include <memory>

/* 如何实现一个Any类型:
 * 任意类型 -> 模板
 * 让一个类型指向其它任意类型 -> 基类指针
 */
// Any类型：可以接受任意数据的类型
class Any
{
public:
    // 创建基本的构造函数
    Any() = default;
    ~Any() = default;
    Any(const Any &) = delete;
    Any &operator=(const Any &) = delete;
    Any(Any &&) = default;
    Any &operator=(Any &&) = default;

    // 这个给构造函数可以让Any类型接受任意其他的数据
    template <typename T>
    Any(T data) : base_(std::make_unique<Derive<T>>(data)) {}

    // 这个方法能Any里面存储的data数据提取出来
    template <typename T>
    T cast()
    {
        // 怎么从base_找到它所指向的Derive对象，从它里面取出data成员变量
        // 基类指针转为派生指针  RTTI
        Derive<T> *pd = dynamic_cast<Derive<T> *>(base_.get());
        if (pd == nullptr)
            throw "type is unmatch!";
        return pd->data_;
    }

private:
    // 基类类型
    class Base
    {
    public:
        virtual ~Base() = default;
    };
    // 派生类类型
    template <typename T>
    class Derive : public Base
    {
    public:
        Derive(T data) : data_(data) {}

        T data_;
    };

private:
    // 定义基类指针
    std::unique_ptr<Base> base_;
};

#endif
