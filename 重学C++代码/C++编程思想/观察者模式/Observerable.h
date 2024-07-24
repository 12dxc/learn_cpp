#pragma once
#include <list>
#include <string>
using namespace std;
#include "Observer.h"

class Observer;

class Observerable
{
public:
    Observerable();
    virtual ~Observerable();

    void Attach(Observer *pOb);

    void Detach(Observer *pOb);

    int GetObserverCount() const
    {
        return _Obs.size();
    }

    void DetachAll()
    {
        _Obs.clear();
    }

protected:
    void setChange(string news);

private:
    void Notify(void *pArg);

    bool _bChange;

    list<Observer *> _Obs;
};
