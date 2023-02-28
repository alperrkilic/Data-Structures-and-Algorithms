#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

int main(void)
{
    struct Rectangle r = {10, 5};
    struct Rectangle *p;

    p = &r;

    cout << p->length << endl;  // using arrow instead of dot
    cout << p->breadth << endl; // using arrow instead of dot

    Rectangle *point;

    // for C++ point = new Rectangle is enough
    point = (struct Rectangle *)malloc(sizeof(struct Rectangle)); // for C

    point->breadth = 15;
    point->length = 7;

    return 0;
}