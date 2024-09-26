#include <iostream>
#include <format>
#include <ranges>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include <memory>
#include <cstdio>
#include <queue>
using namespace std;

class Data
{
public:
        Data(int v1 = 10, int v2 = 20) : ma(v1), mb(v2) {}
        int ma;
        int mb;
};

// lambda 的应用
int main()
{
        // 生成一个可调用的函数
        auto fun1 = [](int a, int b)
        { return a + b; };
        cout << fun1(10, 20) << endl;

        // 访问外部变量
        int a = 10;
        int b = 20;
        auto fun2 = [&]()
        {
                int temp = a;
                a = b;
                b = temp;
        };
        fun2();
        cout << format("a={} b={}", a, b) << endl;

        // 适用于泛型算法，自定义操作方式
        vector<int> v{2, 10, 5, 89, 100, 0, 45};
        ranges::sort(v, [](int a, int b)
                     { return a > b; });
        ranges::for_each(v, [](int a)
                         { cout << a << " "; });
        cout << endl;

        // function可以用来表示lambda的类型
        map<int, function<int(int, int)>> m;
        m[1] = [](int a, int b)
        { return a + b; };
        cout << "10+15: " << m[1](10, 15) << endl;

        // 自定义指针删除器
        // 使用智能指针管理文件句柄，回收时需调用专门的关闭文件函数，而非析构，故需自定义删除器
        unique_ptr<FILE, function<void(FILE *)>>
            ptr1(fopen("1.txt", "w"), [](FILE *pf)
                 { fclose(pf); });

        // 定义优先队列，使用自定义类型时不必重载比较运算符，提高类灵活性
        priority_queue<Data, vector<Data>,
                       function<bool(Data &, Data &)>>
        maxHeap([](Data &d1, Data d2) -> bool
                { return d1.ma > d2.ma; });
        for (int i = 0; i != 10; ++i)
                maxHeap.push(Data(i, i + 7));

        return 0;
}