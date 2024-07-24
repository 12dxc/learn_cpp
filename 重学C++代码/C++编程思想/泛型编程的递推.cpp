#include<iostream>
using namespace std;

//1+2+3...100 --> n*(n+1)/2

template<int n>
struct Sum
{
    enum Value { N = sum<n - 1>::N + n };   //Sum(n)=sum(n-1)+n
};
template<>
struct Sum<1>
{
    enum Value { N = 1 };  //n=1
};

int main()
{
    cout << Sum<100>::N << endl;

    system("pause");
    return 0;
}