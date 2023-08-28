#include<iostream>
#include<functional>
#include<algorithm>
using namespace std;

//C++标准方式，但限定类型
bool MySort(int a, int b)
{
    return a < b;
}
void Display(int a)
{
    cout << a << " ";
}

//C++泛型，不限类型，使代码复用
template<class T>
inline bool MySortT(T const& a, T const& b)  //加const& 用于节省空间，因为泛型可以传递所以类型，内置可不加，但自定义可能很大需要追加
{
    return a < b;
}
template<class T>
void DisplayT(T const& a)
{
    cout << a << " ";
}

//C++仿函数
struct SortF
{
    bool operator()(int a, int b)
    {
        return a < b;
    }
};
struct DisplayF
{
    void operator()(int a)
    {
        cout << a << " ";
    }
};

//C++仿函数模板
template<class T>
struct SortTF
{
    inline bool operator()(T const& a, T const& b)const
    {
        return a < b;
    }
};
template<class T>
struct DisplayTF
{
    inline void operator()(T const& a)const
    {
        cout << a << " ";
    }
};

int main()
{
    //C++方式
    int arr[] = { 4,3,2,1,7 };
    sort(arr, arr + 5, MySort);
    for_each(arr, arr + 5, Display);
    cout << endl;

    //C++泛型
    int arr2[] = { 4,3,2,1,7 };
    sort(arr2, arr2 + 5, MySortT<int>);
    for_each(arr2, arr2 + 5, DisplayT<int>);
    cout << endl;

    //C++函数对象（仿函数）
    int arr3[] = { 4,3,2,1,7 };
    sort(arr3, arr3 + 5, SortF());
    for_each(arr3, arr3 + 5, DisplayF());
    cout << endl;

    //C++仿函数模板
    int arr4[] = { 4,3,2,1,7 };
    sort(arr4, arr4 + 5, SortTF<int>());
    for_each(arr4, arr4 + 5, DisplayTF<int>());
    cout << endl;


    system("pause");
    return 0;
}