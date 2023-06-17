#ifndef POLY
#define POLY
#include <iostream>

class base
{
public:
    virtual void print()
    {
        std::cout << "print base class" << std::endl;
    }
    void show()
    {
        std::cout << "show base class" << std::endl;
    }

    base(/* args */);
    ~base();
};

#endif