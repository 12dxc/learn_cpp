#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // 读入一组整数，将每对相邻整数的和输出
    vector<int> v;
    int i;
    while (cin >> i)
    {
        v.push_back(i);
    }

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] + v[i + 1] << endl;
    }
    cout << "---------------------------------" << endl;

    // 依次输出 1~n-1,2~n-2... 的和
    int m = 0;            // 起始下标
    int n = v.size() - 1; // 末尾下标
    while (m < n)         // 当起始下标超过末尾下标，说明遍历完了整个数组
    {
        cout << v[m] + v[n] << endl;
        m++; // 起始下标向前进一位
        n--; // 末尾下标后退一位
    }

    return 0;
}
