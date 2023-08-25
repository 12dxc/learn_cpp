#include <iostream>
#include<fstream>
using namespace std;

int main()
{
    fstream fout;
    fout.open("testBuffer.txt", ios::app);   //追加方式打开
    //if (fout.fail())   //测试文件打开状态
    if (!fout)    //测试是否为空，只要有数据就不为空
    {
        cout << "文件打开失败" << endl;
    }
    int index = 0;
    int a = 0;
    while (cin >> a)
    {
        fout << "输入的数字是：" << a << endl;
        index++;
        if (index == 5)
        {
            break;
        }
    }
    fout.close();

    system("pause");
    return 0;
}

