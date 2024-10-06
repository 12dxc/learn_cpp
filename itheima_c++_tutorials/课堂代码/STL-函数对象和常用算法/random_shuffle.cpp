#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <ctime>

// 常用排序算法 random_shuffle  指定范围内的元素随机调整次序

void myPrint(int val)
{
    cout << val << " ";
}
void test01()
{
    srand((unsigned int)time(NULL));
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    random_shuffle(v.begin(), v.end());

    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
}

int main()
{

    test01();

    system("pause");
    return 0;
}