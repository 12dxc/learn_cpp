#include <iostream>
#include <vector>
using namespace std;

template <class T>
void myPrint(vector<T> &v)
{
    cout << v.size() << " 内容为: ";
    for (auto i : v)
    {
        cout << i;
    }
    cout << endl;
}

int main()
{
    vector<int> v1;              // size:0,  no values.
    vector<int> v2(10);          // size:10, value:0
    vector<int> v3(10, 42);      // size:10, value:42
    vector<int> v4{10};          // size:1,  value:10
    vector<int> v5{10, 42};      // size:2,  value:10, 42
    vector<string> v6{10};       // size:10, value:""
    vector<string> v7{10, "hi"}; // size:10, value:"hi"

    cout << "v1 的大小为: ";
    myPrint<int>(v1);
    cout << "v2 的大小为: ";
    myPrint<int>(v2);
    cout << "v3 的大小为: ";
    myPrint<int>(v3);
    cout << "v4 的大小为: ";
    myPrint<int>(v4);
    cout << "v5 的大小为: ";
    myPrint<int>(v5);
    cout << "v6 的大小为: ";
    myPrint<string>(v6);
    cout << "v7 的大小为: ";
    myPrint<string>(v7);

    return 0;
}
