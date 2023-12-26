#include <iostream>
#include <memory>
#include <vector>
using namespace std;

// ����һ����̬�����int��vector
shared_ptr<vector<int>> alloc_vector()
{
    return make_shared<vector<int>>();
}
// ��ȡ��׼����
void assign_vector(shared_ptr<vector<int>> p)
{
    int i = 0;
    while (cin >> i)
    {
        p->push_back(i);
    }
}
// ��ӡ�����ֵ
void print_vector(shared_ptr<vector<int>> p)
{
    for (auto i : *p)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    auto v = alloc_vector();
    assign_vector(v);
    print_vector(v);

    return 0;
}