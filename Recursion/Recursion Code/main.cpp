#include <iostream>
#include <stdio.h>

using namespace std;

void fun(int n) // n starts as 3 and therefore there will be 4 calls (from n+1)
{
    if (n > 0)
    {
        printf("%d ", n);
        fun(n - 1);
    }
}

void fun2(int n)
{
    if (n > 0)
    {
        fun2(n - 1);
        printf("%d ", n);
    }
}

int main(void)
{
    int x = 3;
    fun(x);

    cout << endl;

    fun2(x);

    return 0;
}

/*
    NOTE:
        For the first function fun(int n), we can think as a corridor of room, light the bulb and continue to the next room
        but for the second function first it goes to through all rooms and then light the bulbs in the reverse order
*/