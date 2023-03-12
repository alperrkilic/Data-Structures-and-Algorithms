#include <stdio.h>
#include <iostream>

void funB(int n);
void funA(int n);

using namespace std;

void funB(int n)
{
    if (n > 1)
    {
        printf("%d ", n);
        funA(n / 2);
    }
}

void funA(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        funB(n - 1);
    }
}

int main(void)
{
    funA(20);
    return 0;
}