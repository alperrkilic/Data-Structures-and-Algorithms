#ifndef DERIVED
#define DERIVED
#include "poly.h"

class derived : public base
{
public:
    virtual void print() override // it is also okay if we don't indicate virtual here but, writing is the best practice
    {
        std::cout << "print derived class" << std::endl;
    }
    void show() // non-virtual function (belongs to derived class)
    {
        std::cout << "show derived class" << std::endl;
    }

    derived(/* args */);
    ~derived();
};

#endif