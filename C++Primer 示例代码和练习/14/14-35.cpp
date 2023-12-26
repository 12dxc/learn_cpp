#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Input
{
    string operator()(string &s)
    {
        string str;
        getline(is, str);         // 读取一行
        return is ? s : string(); // 读取成功，返回读取值，失败则返回空字符串
    }

private:
    istream &is = cin;
};

int main()
{

    system("pause");
    return 0;
}