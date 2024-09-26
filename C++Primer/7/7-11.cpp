#include <iostream>
using namespace std;
#include "7-11.h"

int main()
{
     Sales_data item1;
     print(cout, item1);

     Sales_data item2("0-201-78345-X");
     print(cout, item2);

     Sales_data item3("0-201-78345-X", 20, 2.00);
     print(cout, item3);

     Sales_data item4(cin);
     print(cout, item4);

     return 0;
}