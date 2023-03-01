#include <iostream>
#include "poly.h"
#include "derived.h"

using namespace std;

int main(void)
{
    base *baseptr;
    derived d;
    baseptr = &d;

    // Now base pointer is pointing to a place where derived object is found and derived IS A base
    // Since print() method has been overridden in derived class, when we call print method for baseptr we will see : print derived class
    // However, since show is not defined, when we call the show() method, it won't be bind dynamically and the method of the base class will be called
    // therefore, the output is: show base class

    baseptr->print();
    baseptr->show();

    return 0;
}