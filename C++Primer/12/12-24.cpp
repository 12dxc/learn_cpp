#include <iostream>
#include <memory>
#include <cstring>
#include <string>
using namespace std;

int main()
{
    cout << "你想输入一个多大的字符串?" << endl;
    int size = 0;
    cin >> size;
    char *input = new char[size + 1]();
    // 清空输入缓冲区    因为上一次输入可能造成缓冲区残留
    cin.ignore();
    cout << "请输入字符串: ";
    // get 二参数形式，用于读取一行 第一个为要输入的字符 n表示目标空间的大小。
    cin.get(input, size + 1);
    cout << input;
    // 释放动态数组
    delete[] input;

    return 0;
}