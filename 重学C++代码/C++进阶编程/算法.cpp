#include<iostream>
#include<functional>
#include<numeric>
#include<algorithm>
#include<vector>
using namespace std;


int main()
{
    //transform和lambda表达式
    int ones[] = { 1,2,3,4,5 };
    int tows[] = { 10,20,30,40,50 };
    int results[5];
    //数组元素依次相加，并返回
    transform(ones, ones + 5, tows, results, plus<int>());
    for_each(results, results + 5, [](int a)->void {cout << a << " "; });  //lambda表达式（匿名函数）
    cout << endl;

    //find
    int arr[] = { 0,1,2,3,3,4,4,5,6,6,7,7,7,8 };
    vector<int>iA{ arr + 2,arr + 6 };   //{2,3,3,4}
    int len = sizeof(arr) / sizeof(arr[0]);
    //count()  统计元素的个数
    cout << count(arr, arr + len, 7) << endl;
    //统计一个区间的元素个数
    cout << count_if(arr, arr + sizeof(arr) / sizeof(arr[0]), bind2nd(less<int>(), 7)) << endl;
    //二分查找  查找单个元素，查到返回1，查不到返回0
    cout << binary_search(arr, arr + len, 8) << endl;
    //查找一个区间，查找区间，查到返回区间第一个元素首地址
    cout << *search(arr, arr + len, iA.begin(), iA.end()) << endl;

    system("pause");
    return 0;
}