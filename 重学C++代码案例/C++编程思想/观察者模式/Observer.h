#pragma once
#ifndef OBSEVER_H_1
#define OBSEVER_H_1

class Observer
{
public:
    Observer() { ; };
    virtual ~Observer() { ; };

   
    virtual void Update(void* pArg) = 0;
};

#endif

