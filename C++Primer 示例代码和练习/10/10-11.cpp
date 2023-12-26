#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// ��Ԫν�ʣ�������ָ��sort�������
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() > s2.size();
}

template <typename T>
auto println(T const &elem) -> ostream &
{
    for (auto const &i : elem)
    {
        cout << i << " ";
    }
    return cout << endl;
}

auto elimDups(vector<string> &v) -> vector<string> &
{
    sort(v.begin(), v.end(), isShorter);
    println(v);

    // ʹ��ֻ�������εĵ���������ǰ����������ָ���ظ�����֮���һ��������
    auto end_unique = unique(v.begin(), v.end());
    println(v);

    v.erase(end_unique, v.end());
    return v;
}

int main()
{
    vector<string> v{
        "1234", "1234", "1234", "Hi", "alan", "wang"};
    elimDups(v);
    // ���ֵ��򣬵��г�������ν��
    stable_sort(v.begin(), v.end(), isShorter);
    cout << "ex10.11 :\n";
    println(v);

    return 0;
}