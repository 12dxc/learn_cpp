#include <iostream>
#include <vector>
#include <string>
using namespace std;

class GetInput
{
public:
    GetInput(istream &i = cin) : is(i) {}
    string operator()() const
    {
        string str;
        getline(is, str);           // 读取一行
        return is ? str : string(); // 读取成功，返回读取值，失败则返回空字符串
    }

private:
    istream &is;
};

int main()
{
    GetInput input;
    vector<string> vs;
    for (string tmp; !(tmp = input()).empty();)
        vs.push_back(tmp);
    for (const auto &i : vs)
        cout << i << " ";
    cout << endl;

    system("pause");
    return 0;
}