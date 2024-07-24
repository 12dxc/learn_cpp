#include<thread>
#include<mutex>
#include<iostream>
using namespace std;


int main()
{
    //线程交换
    thread tW1([]() {
        cout << "交换线程1结束" << endl;
        });
    thread tW2([]() {
        cout << "交换线程2结束" << endl;
        });
    cout << "交换线程1的id是：" << tW1.get_id() << endl;
    cout << "交换线程2的id是：" << tW2.get_id() << endl;

    cout << "线程交换后：" << endl;
    swap(tW1, tW2);     //线程交换
    cout << "交换线程1的id是：" << tW1.get_id() << endl;
    cout << "交换线程2的id是：" << tW2.get_id() << endl;

    tW1.join();
    tW2.join();

    //线程移动  使用权转移
    thread tM1([]() {cout << "移动线程1结束" << endl; });
    cout << "移动线程1的id是：" << tM1.get_id() << endl;
    cout << "线程移动后" << endl;
    thread tM2(move(tM1));
    cout << "移动线程2的id是：" << tM2.get_id() << endl;
    tM2.join();


    system("pause");
    return 0;
}