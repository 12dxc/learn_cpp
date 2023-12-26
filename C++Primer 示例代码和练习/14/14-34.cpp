#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Test
{
    int operator()(bool b, int Ta, int Tb)
    {
        return b ? Ta : Tb;
    }
};

int main()
{

    system("pause");
    return 0;
}