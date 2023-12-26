#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

template <class T>
class StrBlob
{
public:
    typedef vector<string>::size_type size_type;
    StrBlob() : data(make_shared<vector<string>>()) {}
    StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    // 添加和删除元素
    void push_back(const string &t) { data->push_back(t); }
    void pop_back()
    {
        check(0, "StrBlob 尾元素为空");
        data->pop_back();
    }
    // 元素访问
    string &front() const
    {
        check(0, "StrBlob 头元素为空");
        return data->front();
    }
    string &back() const
    {
        check(0, "StrBlob 尾元素为空");
        return data->back();
    }

private:
    shared_ptr<vector<string>> data;
    // 如果data[i]不合法，抛出一个异常
    void check(size_type i, const string &msg) const
    {
        if (i >= data->size())
            throw out_of_range(msg);
    }
};

int main()
{

    return 0;
}