#include<thread>
#include<mutex>
#include<iostream>
using namespace std;


//存钱
void Deposit(mutex& m, int& money)
{
    //锁的粒度尽可能的最小化
    for (int i = 0; i < 100; i++)
    {
        m.lock();
        money += 1;
        m.unlock();
    }
}

//取钱
void Withdraw(mutex& m, int& money)
{
    for (int i = 0; i < 100; i++)
    {
        m.lock();
        money += 1;
        m.unlock();
    }
}

int main()
{
    //银行存取款
    int money = 2000;
    mutex m;

    //thread 中使用引用必须加，ref() 表示维持一个指针
    cout << "当前的钱是多少：" << money << endl;
    thread t1(Deposit, ref(m), ref(money));
    thread t2(Withdraw, ref(m), ref(money));

    t1.join();
    t2.join();
    cout << "存取后的钱是多少：" << money << endl;


    system("pause");
    return 0;
}