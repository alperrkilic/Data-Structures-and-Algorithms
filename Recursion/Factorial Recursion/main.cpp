#include <iostream>

using namespace std;

int recursiveFact(int n)
{
    if (n == 0) // 0! = 1
    {
        return 1;
    }
    else
    {
        return recursiveFact(n - 1) * n;
    }
}

int main(void)
{

    int n;
    cout << "Please enter n: ";
    cin >> n;

    cout << n << "! is: " << recursiveFact(n);

    return 0;
}

/*
    Logic is simple: n! = 1*2*3*...*(n-1)*n
    n! = (n-1)! * n; therefore, we should call the recursive function if n is not 0
*/