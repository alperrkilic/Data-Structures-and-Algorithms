#include <iostream>
#include <stdio.h>

using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

int calculateArea(struct Rectangle &r)
{
    return r.breadth * r.length;
}

void changeLength(struct Rectangle *p, int l)
{
    p->length = l;
}

void display(struct Rectangle &r)
{
    cout << "Length: " << r.length << endl
         << "Breadth: " << r.breadth << endl;
}

int main(void)
{
    struct Rectangle r = {10, 5};
    int area{0};

    area = calculateArea(r);
    cout << "Area is: " << area << endl;

    changeLength(&r, 20);
    cout << "The new length is: " << r.length << endl;

    cout << endl;
    display(r);

    return 0;
}