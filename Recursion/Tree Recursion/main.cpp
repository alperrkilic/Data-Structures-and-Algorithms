#include <stdio.h>
#include <iostream>

using namespace std;

void fun(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        fun(n - 1);
        fun(n - 1);
    }
}

int main(void)
{
    fun(3);
    return 0;
}

/*
    It should be noted that, at the 11th line, the function continues until n is zero, after its finished the value of n is again 3 since the value of
    n was 3 when the function called at 11th line. after 11th line is terminated, now it continues as if n is 3 therefore now again will process the same and output 2 1 1
    so at the first call it is 3 (10th line) at 11th and 12th line it will be 2 1 1 and 2 1 1
    output is: 3 2 1 1 2 1 1
*/