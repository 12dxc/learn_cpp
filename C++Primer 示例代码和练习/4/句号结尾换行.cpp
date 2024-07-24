#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<string> vStr = {"hello", "world.", "HI"};
    // string对象可能非常大，所以将s声明为引用类型可以避免对元素的拷贝，
    // 但又因为不对string对象做读写操作，所以s被声明为常量引用
    for (const auto &s : vStr)
    {
        cout << s;
        if (s.empty() || s[s.size() - 1] == '.')
        {
            cout << endl;
        }
        else
        {
            cout << " ";
        }
    }

    return 0;
}
