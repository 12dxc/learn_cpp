#include <iostream>
#include <memory>
#include <vector>
using namespace std;

// ����һ����̬�����int��vector
vector<int> *alloc_vector()
{
    return new vector<int>();
}
// ��ȡ��׼����
void assign_vector(vector<int> *p)
{
    int i = 0;
    while (cin >> i)
    {
        p->push_back(i);
    }
}
// ��ӡ�����ֵ
void print_vector(vector<int> *p)
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