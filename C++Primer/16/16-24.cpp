#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <initializer_list>
#include <list>
using namespace std;

// 前置声明，在Blob中声明友元所需要的
template <typename>
class BlobPtr;
template <typename>
class Blob; // 运算符==中的参数所需要的
template <typename T>
bool operator==(const Blob<T> &, const Blob<T> &);

template <typename T>
class Blob
{
public:
    // 每个Blob实例将访问权限授予用相同类型实例化的BlobPtr和相等运算符
    friend class BlobPtr<T>;
    friend bool operator==(const Blob<T> &, const Blob<T> &);

    typedef T value_type;
    // typename 后面的字符串为一个类型名称，而不是成员函数或者成员变量
    typedef typename vector<T>::size_type size_type;
    // 构造函数
    Blob();
    Blob(initializer_list<T> il);
    template <typename It>
    Blob(It b, It e);

    // Blob中的元素数目
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    // 添加和删除元素
    void push_back(const T &t) { data->push_back(t); }
    void push_back(T &&t) { return data->push_back(move(t)); }
    void pop_back();
    // 元素访问
    T &back();
    T &operator[](size_type i);

    const T &back() const;
    const T &operator[](size_type i) const;

private:
    shared_ptr<vector<T>> data;
    // 若data[i]无效，则抛出msg
    void check(size_type i, const string &msg) const;
};
template <typename T>
Blob<T>::Blob() : data(make_shared<vector<T>>()) {}
template <typename T>
Blob<T>::Blob(initializer_list<T> il) : data(make_shared<vector<T>>(il)) {}
template <typename T>
template <typename It>
Blob<T>::Blob(It b, It e) : data(make_shared<vector<T>>(b, e)) {}

template <typename T>
void Blob<T>::check(size_type i, const string &msg) const
{
    if (i >= data->size())
        throw out_of_range(msg);
}
template <typename T>
T &Blob<T>::back()
{
    check(0, "尾元素为空");
    return data->back();
}
template <typename T>
const T &Blob<T>::back() const
{
    check(0, "尾元素为空");
    return data->back();
}

template <typename T>
T &Blob<T>::operator[](size_type i)
{
    // 如果i太大，check会抛出异常，阻止访问一个不存在的元素
    check(i, "下标超出范围");
    return (*data)[i];
}
template <typename T>
const T &Blob<T>::operator[](size_type i) const
{
    check(i, "下标超出范围");
    return (*data)[i];
}

template <typename T>
void Blob<T>::pop_back()
{
    check(0, "尾元素为空，无法删除");
    data->pop_back();
}

template <typename T>
class BlobPtr
{
public:
    BlobPtr() : curr(0) {}
    BlobPtr(Blob<T> &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    T &operator*() const
    {
        auto p = check(curr, "引用结束");
        return (*p)[curr]; //(*p)为本对象指向的vector
    }
    // 递增和递减
    BlobPtr &operator++();
    BlobPtr &operator--();

    BlobPtr operator++(int);
    BlobPtr operator--(int);

private:
    // 若检查成功，check返回一个指向vector的shared_ptr
    shared_ptr<vector<T>> check(size_t, const string &) const;
    // 保存一个weak_ptr,表示底层vector可能被销毁
    weak_ptr<vector<T>> wptr;
    size_t curr; // 数组中的当前位置
};
template <typename T>
BlobPtr<T> &BlobPtr<T>::operator++()
{
    // 此处无需检查；调用前置递增时会进行检查
    BlobPtr ret = *this; // 保存当前值
    ++*this;             // 推进一个元素；前置++检查递增是否合法
    return ret;          // 返回保存的状态
}

// postfix --
template <typename T>
BlobPtr<T> &BlobPtr<T>::operator--()
{
    BlobPtr ret = *this;
    --*this;

    return ret;
}
// postfix ++
template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
    BlobPtr ret = *this;
    ++*this;

    return ret;
}

// postfix --
template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int)
{
    BlobPtr ret = *this;
    --*this;

    return ret;
}

template <typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    if (lhs.wptr.lock() != rhs.wptr.lock())
    {
        throw runtime_error("ptrs to different Blobs!");
    }
    return lhs.i == rhs.i;
}

template <typename T>
bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    if (lhs.wptr.lock() != rhs.wptr.lock())
    {
        throw runtime_error("ptrs to different Blobs!");
    }
    return lhs.i < rhs.i;
}

main()
{
    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<long> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<const char *> w{"now", "is", "the", "time"};

    Blob<int> a1(begin(ia), end(ia));

    Blob<int> a2(vi.begin(), vi.end());

    Blob<string> a3(w.begin(), w.end());

    return 0;
}
