#include <iostream>
using namespace std;
#include "MyComplex.h"

int main()
{
    Complex a(1.0, 2.0);
    cout << a.getReal() << endl;
    cout << a.getImage() << endl;
    a.setImage(2.0);
    a.setReal(3.0);
    cout << a.getReal() << endl;
    cout << a.getImage() << endl;

    Complex b(2.0, 3.0);
    Complex c = a + b;
    Complex d(c);

    Complex e;
    e = d++;
    cout << d << endl;
    cout << e << endl;
    e = ++d;
    cout << d << endl;
    cout << e << endl;
    cout << (e == d) << endl; // 1
    cout << (e != a) << endl; // 0

    cin >> e;
    cout << e << endl;

    system("pause");
    return 0;
}
