#include <iostream>
#include <vector>
using namespace std;

// C语言数组
double average1(int arr[10]) // 产生了数组退化，实际传入的是一个数组名
{
    double result = 0.0;
    int len = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < len; i++)
    {
        result += arr[i];
    }

    return result / len;
}
// C语言不支持传入数组，故将长度在外计算然后传入
double average2(int *arr, int len)
{
    double result = 0.0;
    for (int i = 0; i < len; i++)
    {
        result += arr[i];
    }

    return result / len;
}

// C++数组
// 一维数组求平均值
double average3(vector<int> &v)
{
    double result = 0.0;
    vector<int>::iterator it = v.begin();

    for (; it != v.end(); it++)
    {
        result += *it;
    }

    return result / v.size();
}
// 二维数组求平均值
double average2DV(vector<vector<int>> &vv)
{
    double result = 0.0;
    int size = 0;

    for (int i = 0; i < vv.size(); i++)
    {
        for (int j = 0; j < vv[i].size(); j++)
        {
            result += vv[i][j];
            size += 1;
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }

    return result / size;
}

int main()
{
    int array1[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int len = sizeof(array1) / sizeof(array1[0]);
    cout << average1(array1) << endl;
    cout << average2(array1, len) << endl;

    vector<int> vt = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    cout << average3(vt) << endl;
    vector<vector<int>> vv2D = {8, vector<int>(12, 3)};
    cout << average2DV(vv2D) << endl;

    return 0;
}