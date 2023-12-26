#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;
#include "15-5.h"

int main()
{

    Quote q("textbook", 10.60);
    Bulk_quote bq("textbook", 10.60, 10, 0.3);

    print_total(std::cout, q, 12);
    print_total(std::cout, bq, 12);

    return 0;
}