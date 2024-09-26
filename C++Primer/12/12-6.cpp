#include <iostream>
#include <memory>
#include <vector>
using namespace std;

// 返回一个动态分配的int的vector
vector<int> *alloc_vector()
{
    return new vector<int>();
}
// 读取标准输入
void assign_vector(vector<int> *p)
{
    int i = 0;
    while (cin >> i)
    {
        p->push_back(i);
    }
}
// 打印读入的值
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