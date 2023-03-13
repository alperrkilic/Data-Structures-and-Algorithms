#include <iostream>
#include <stdio.h>

using namespace std;

int recursiveSum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return recursiveSum(n - 1) + n;
    }
}

int sumFormula(int n)
{
    return n * (n + 1) / 2;
}

int loopSum(int n)
{
    int i, s = 0;

    for (i = 1; i <= n; i++)
    {
        s = s + i;
    }
    return s;
}

int main(void)
{
    cout << "n = 5" << endl;
    cout << "Recursive Sum: " << recursiveSum(5) << endl;
    cout << "Formula Sum: " << sumFormula(5) << endl;
    cout << "Loop Sum: " << loopSum(5) << endl;

    return 0;
}