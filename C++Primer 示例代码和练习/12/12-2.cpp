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
    // ��Ӻ�ɾ��Ԫ��
    void push_back(const string &t) { data->push_back(t); }
    void pop_back()
    {
        check(0, "StrBlob βԪ��Ϊ��");
        data->pop_back();
    }
    // Ԫ�ط���
    string &front() const
    {
        check(0, "StrBlob ͷԪ��Ϊ��");
        return data->front();
    }
    string &back() const
    {
        check(0, "StrBlob βԪ��Ϊ��");
        return data->back();
    }

private:
    shared_ptr<vector<string>> data;
    // ���data[i]���Ϸ����׳�һ���쳣
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