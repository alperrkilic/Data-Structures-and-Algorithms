#include <iostream>

using namespace std;

double e(int x, int n)
{
    static double s = 1;

    if (n == 0)
    {
        return s;
    }
    else
    {
        s = 1 + x * (s / n);
    }
    return e(x, n - 1);
}

double loop_function(double x, double n)
{
    double s = 1;

    for (; n > 0; n--)
    {
        s = (1 + ((x / n) * s));
    }
    return s;
}

int main(void)
{
    int degree;
    int n;
    cout << "Enter the degree of 'e': ";
    cin >> degree;
    cout << "Enter the number of terms: ";
    cin >> n;
    cout << "Result is: " << e(degree, n);

    cout << "With function Result is: " << loop_function(degree, n) << endl;

    return 0;
}