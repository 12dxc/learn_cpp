#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#include "../7/7-26.h"

bool compareIsbn(Sales_data &item1, Sales_data &item2)
{
    return item1.isbn() > item2.isbn();
}

int main()
{
    Sales_data d1("aa"), d2("aaaa"), d3("aaa"), d4("z"), d5("aaaaz");
    vector<Sales_data> v{d1, d2, d3, d4, d5};

    sort(v.begin(), v.end(), compareIsbn);

    for (auto const &i : v)
        cout << i.isbn() << " ";
    cout << endl;

    return 0;
}