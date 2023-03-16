#include <iostream>

using namespace std;

int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return fact(n - 1) * n;
    }
}

int nCr(int n, int r)
{
    int t1, t2, t3;

    t1 = fact(n);
    t2 = fact(r);
    t3 = fact(n - r);

    return t1 / (t2 * t3);
}

int nCr_recursive(int n, int r)
{
    if (n == r || r == 0)
    {
        return 1;
    }
    else
    {
        return nCr_recursive(n - 1, r - 1) + nCr_recursive(n - 1, r);
    }
}

int main(void)
{
    int n, r;

    cout << "Please enter C(n,r): ";
    cin >> n >> r;
    cout << "The Result with factorial is: " << nCr(n, r) << endl;
    cout << "The result with Recursive form is: " << nCr_recursive(n, r) << endl;

    return 0;
}