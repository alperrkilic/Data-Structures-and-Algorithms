#include <iostream>
#include <stdio.h>

using namespace std;

int fun(int n)
{
    if (n > 0)
    {
        return fun(n - 1) + n;
    }
    return 0;
}

int fun2(int n)
{
    static int x = 0; // declared onload, and only once. If it was global variable the result would be same
    if (n > 0)
    {
        x++;
        return fun2(n - 1) + x;
    }
    return 0;
}

int main(void)
{
    int r;
    r = fun(5);
    printf("For fun(5): %d\n", r);

    int k;
    k = fun2(5);
    printf("For fun2(5): %d\n", k);

    return 0;
}