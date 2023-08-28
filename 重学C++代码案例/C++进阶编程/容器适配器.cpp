#include<iostream>
#include<stack>
#include<queue>
#include<functional>
using namespace std;


int main()
{
    stack<int>s;
    queue<int>q;

    priority_queue<int>pq;    //默认最大值优先
    priority_queue<int, vector<int>, less<int>>pq2;      //最大值优先
    priority_queue<int, vector<int>, greater<int>>pq3;   //最小值优先

    pq.push(2);
    pq.push(1);
    pq.push(3);
    pq.push(0);

    //循环输出优先队列
    while (!pq.empty())
    {
        int top = pq.top();
        cout << "顶部元素为:" << top << endl;
        pq.pop();
    }
    cout << endl;

    system("pause");
    return 0;
}