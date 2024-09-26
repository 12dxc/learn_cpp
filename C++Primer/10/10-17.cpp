#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#include "../7/7-26.h"

int main()
{
    Sales_data d1("aa"), d2("aaaa"), d3("aaa"), d4("z"), d5("aaaaz");
    vector<Sales_data> v{d1, d2, d3, d4, d5};

    sort(v.begin(), v.end(), [](Sales_data &i1, Sales_data &i2)
         { return i1.isbn() > i2.isbn(); });

    for_each(v.begin(), v.end(), [](Sales_data &i)
             { cout << i.isbn() << " "; });
    cout << endl;

    return 0;
}