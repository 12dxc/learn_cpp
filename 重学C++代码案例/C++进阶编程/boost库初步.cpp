#include<iostream>
using namespace std;
#include<boost/lexical_cast.hpp>
using boost::lexical_cast;


int main()
{
    int i = lexical_cast<int>("123");
    cout << i << endl;

    string s = lexical_cast<string>(1.23);
    cout << s << endl;

    int ii;
    try {
        ii = lexical_cast<int>("aabb");

    }
    catch (boost::bad_lexical_cast& e)
    {
        cout << e.what() << endl;
    }

    system("pause");
    return 0;
}