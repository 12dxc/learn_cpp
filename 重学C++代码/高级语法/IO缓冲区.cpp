#include <iostream>
using namespace std;

int main()
{
    int a;
    int index = 0;
    while (cin >> a)      //程序未回车时，数据会一直存在缓冲区
    {
        //回车后依次赋值
        cout << a << endl;
        index++;
        if (index == 5)
        {
            break;
        }
    }

    //假设数据多输入了一个，才换行，那么便会直接跳过下面的输入直接赋值，因为已有数据，这叫脏数据污染
    //清空缓冲区数据
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');   //参数一，表示整数值最大范围
    char ch;
    cin >> ch;
    cout << "你的名字是：" << ch << endl;

    system("pause");
    return 0;
}

