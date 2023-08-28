#include<iostream>
#include<list>
using namespace std;


int main()
{
    list<int>v;
    v.push_back(3);
    v.push_back(4);
    v.push_front(2);
    v.push_front(1);

    list<int>::const_iterator it = v.begin();
    for (; it != v.end(); it++)  //注意迭代器不支持 "<"
    {
        //*it += 1;  //使用常量迭代器，如果修改会触发异常
        cout << *it << " ";
    }
    cout << endl;

    cout << v.front() << endl;
    v.pop_front();     //从顶部去除

    list<int>::reverse_iterator it2;
    for (it2 = v.rbegin(); it2 != v.rend(); it2++)
    {
        *it2 += 1;
        cout << *it2 << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}