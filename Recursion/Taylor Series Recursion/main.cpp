#include <iostream>

using namespace std;

double e(int x, int n)
{
    double result = 0;
    static double p = 1;
    static double f = 1;

    if (n == 0)
    {
        return 1;
    }
    else
    {
        result = e(x, n - 1);
        p = p * x;
        f = f * n;
        return result + p / f;
    }
}

int main(void)
{
    int x, n;
    cout << "Enter the degree of e you want to calculate: ";
    cin >> x;
    cout << "Enter the number of terms: ";
    cin >> n;
    cout << "Result is: " << e(x, n);

    return 0;
}