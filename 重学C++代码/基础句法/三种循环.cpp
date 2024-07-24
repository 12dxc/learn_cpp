#include <iostream>
using namespace std;

//三种循环for、while、do...while
int main()
{
    //TODO：1+2+3+4...+100
    //while语句
    int sum = 0;
    int index = 1;
    while (index <= 100)
    {
        sum += index;
        index++;
    }
    //cout << sum << endl;

    //for循环   
    sum = 0;
    index = 1;
    for (; index <= 100; index++)
    {
        sum += index;
    }
    //cout << sum << endl;

    sum = 0;
    index = 1;
    //do...while语句
    do
    {
        sum += index;
        index++;
    } while (index <= 100);
    //cout << sum << endl;

    system("pause");
    return 0;
}