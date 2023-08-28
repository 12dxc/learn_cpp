#include<iostream>
#include<vector>
#include<list>
#include<stack>
#include<queue>
using namespace std;

struct Dispaly
{
    void operator()(int i)
    {
        cout << i << " ";
    }
};

int main()
{
    int iArr[] = { 1,2,3,4,5 };

    vector<int>iVector(iArr, iArr + 4);     //向量数组（动态数组）
    list<int>iList(iArr, iArr + 4);         //列表（链表）
    deque<int>iDeque(iArr, iArr + 4);       //双端数组

    //栈和队列是加了限制的双端数组，所以用双端数组来初始化
    queue<int>iQueue(iDeque);               //队列  先进先出
    stack<int>iStack(iDeque);               //栈  后进先出
    priority_queue<int>iPQueue(iArr, iArr + 4);     //优先队列，按优先权

    //遍历序列式容器
    //for_each() 对容器中每个元素分别做一个函数的处理
    for_each(iVector.begin(), iVector.end(), Dispaly());
    cout << endl;
    for_each(iList.begin(), iList.end(), Dispaly());
    cout << endl;
    for_each(iDeque.begin(), iDeque.end(), Dispaly());
    cout << endl;

    //遍历容器适配器
    while (!iQueue.empty())
    {
        cout << iQueue.front() << " ";
        iQueue.pop();
    }
    cout << endl;
    while (!iStack.empty())
    {
        cout << iStack.top() << " ";
        iStack.pop();
    }
    cout << endl;
    while (!iPQueue.empty())
    {
        cout << iPQueue.top() << " ";
        iPQueue.pop();
    }
    cout << endl;


    system("pause");
    return 0;
}