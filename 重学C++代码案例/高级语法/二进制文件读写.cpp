#include <iostream>
#include<string>
using namespace std;
#include <fstream>

static const int bufferLen = 2048;

bool copyFile(const string& src, const string& dst)
{
    //打开源文件和目标文件
    //源文件以二进制读的方式打开
    //目标文件以二进制写的方式打开
    ifstream in(src.c_str(), ios::in | ios::binary);
    ofstream out(dst.c_str(), ios::out | ios::trunc | ios::binary);

    //判断文件是否打开成功，失败返回false
    if (!in || !out)
    {
        return false;
    }

    //源文件读取数据，写道目标文件当中
    //通过读取源文件的EOF判断读写是否结束

    char temp[bufferLen];
    while (!in.eof())
    {
        in.read(temp, bufferLen);   //参数2 读文件的最大数

        streamsize count = in.gcount();

        out.write(temp, count);    //参数1 写入的内容，参数2 字符的长度
    }

    //关闭文件
    in.close();
    out.close();

    return true;
}

int main()
{
    cout << copyFile("1.mp3", "2.mp3") << endl;

    system("pause");
    return 0;
}

