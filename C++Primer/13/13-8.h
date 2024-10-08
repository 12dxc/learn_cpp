#include <string>
using namespace std;

class HasPtr
{
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
    HasPtr(const HasPtr &hp) : ps(new string(*hp.ps)), i(hp.i) {}
    HasPtr &operator=(const HasPtr &hp)
    {
        string *new_ps = new string(*hp.ps);
        delete ps;
        ps = new_ps;
        i = hp.i;
        return *this;
    }

private:
    string *ps;
    int i;
};
