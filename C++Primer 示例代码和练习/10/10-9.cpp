#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

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
    sort(v.begin(), v.end());
    println(v);

    // ʹ��ֻ�������εĵ���������ǰ����������ָ���ظ�����֮���һ��������
    auto end_unique = unique(v.begin(), v.end());
    println(v);

    v.erase(end_unique, v.end());
    return v;
}

int main()
{
    vector<string> vs{"a", "v", "a", "s", "v", "a", "a"};
    println(vs);
    println(elimDups(vs));
    return 0;
}