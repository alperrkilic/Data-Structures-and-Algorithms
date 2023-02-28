#include <iostream>
#include <stdio.h>

using namespace std;

struct Rectangle
{
    int length;
    int breadth;
    char x;
}; // r2, r3; (can be also initialized in that way)

int main(void)
{
    struct Rectangle r1 = {10, 5};

    printf("%d\n", sizeof(r1)); // will print out 12 bytes (padding) store 4 bytes, and use 1 byte

    cout << "Length: " << r1.length << endl;
    cout << "Breadth: " << r1.breadth << endl;

    return 0;
}

// std::cout << sizeof(a) << std::endl; // will print out 8 even if the length and breadth is not assigned
