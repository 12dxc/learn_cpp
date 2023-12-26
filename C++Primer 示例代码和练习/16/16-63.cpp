#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
size_t get_count(const vector<T> &v, T t)
{
    size_t count = 0;
    for (auto i : v)
    {
        if (i == t)
            ++count;
    }
    return count;
}
// 针对string的特例化版本
size_t get_count(const vector<string> &v, const char *p)
{
    string s(p);
    size_t count = 0;
    for (auto i : v)
    {
        if (i == s)
            ++count;
    }
    return count;
}

int main()
{
    vector<double> v1{0.14, 3.14, 3.14, 3.14, 0.15};
    vector<int> v2{1, 2, 3, 3, 3, 4, 4, 5};
    vector<string> v3{"hi", "hello", "hi"};
    cout << get_count(v1, 3.14) << endl;
    cout << get_count(v2, 3) << endl;
    cout << get_count(v3, "hi") << endl;

    system("pause");
    return 0;
}