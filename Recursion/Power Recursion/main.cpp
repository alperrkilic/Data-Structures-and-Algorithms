#include <iostream>

using namespace std;

int recursiveFunc1(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return recursiveFunc1(m, n - 1) * m;
    }
}

int recursiveFunc2(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n % 2 == 0) // 2^8 can be represented as ((2)^2)^4 while 4 is half of the n
    {
        return recursiveFunc2(m * m, n / 2);
    }
    else // 2^9 can be represented as (2^2)^4 * 2 while 4 is (n-1)/2
    {
        return m * recursiveFunc2(m * m, (n - 1) / 2);
    }
}

int main(void)
{
    int m, n;
    cout << "Please enter m and n (m^n): ";
    cin >> m >> n;

    cout << "Function 1: " << recursiveFunc1(m, n) << endl;
    cout << "Function 2: " << recursiveFunc2(m, n) << endl;

    return 0;
}

/*
    First Function & Recursive Logic:
        pow(m,n) --> m*m*m*m*m....m (n times)
        pow(m,n) --> pow(m,n-1)*m;
*/

/*
    Second Function & Recursive Logic:
        2^8 can be represented as (2^2)^4 , (m*m)^(n/2)
        2^9 can be represented as 2*(2^2)^4 , (m*m)^(n-1/2)*m
*/