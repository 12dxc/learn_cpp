#include<iostream>
using namespace std;
#include"Observer.h"
#include"Observerable.h"

class News :public Observerable
{
public:
    virtual void GetSomeNews(string str)
    {
        setChange("News:" + str);
    }
};

class  User1 :public Observer
{
    void Update(void* pArg)
    {
        cout << "User1" << (char*)pArg << endl;
    }
};
class  User2 :public Observer
{
    void Update(void* pArg)
    {
        cout << "User2" << (char*)pArg << endl;
    }
};


int main()
{
    User1 u1;
    User2 u2;

    News n1;
    n1.GetSomeNews("T0");
    cout << n1.GetObserverCount() << endl;   // 0

    n1.Attach(&u1);
    n1.Attach(&u2);
    n1.GetSomeNews("T1");    // 2

    n1.Detach(&u2);
    n1.GetSomeNews("T2");    // 1

    n1.DetachAll();
    n1.GetSomeNews("T3");    // 0

    system("pause");
    return 0;
}