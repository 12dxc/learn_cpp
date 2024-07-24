#include "Observerable.h"
Observerable::Observerable()
{
    _bChange = false;
}
Observerable::~Observerable()
{
}

void Observerable::Attach(Observer *pOb)
{
    if (pOb == NULL)
    {
        return;
    }

    auto it = _Obs.begin();
    for (; it != _Obs.end(); it++)
    {
        if (*it == pOb)
        {
            return;
        }
    }

    _Obs.push_back(pOb);
}

void Observerable::Detach(Observer *pOb)
{

    if ((pOb == NULL) || (_Obs.empty() == true))
    {
        return;
    }
    else
    {
        _Obs.remove(pOb);
    }
}

void Observerable::setChange(string news)
{
    _bChange = true;
    Notify((void *)news.c_str());
}

void Observerable::Notify(void *pArg)
{
    if (_bChange == false)
    {
        return;
    }

    auto it = _Obs.begin();
    for (; it != _Obs.end(); it++)
    {
        it->Update(pArg);
    }
    _bChange = false;
}