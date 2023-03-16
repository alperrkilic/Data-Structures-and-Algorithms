#include <iostream>

using namespace std;

int F[100];

int loop_fib(int n)
{
    int t0{0}, t1{1}, s{0};

    if (n < 0)
    {
        throw n;
    }

    if (n <= 1 && n >= 0)
    {
        return n;
    }

    for (int i = 2; i <= n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

int excessive_recursive_fib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return excessive_recursive_fib(n - 2) + excessive_recursive_fib(n - 1);
}

void initialize_array()
{
    for (int i = 0; i < 100; i++)
    {
        F[i] = -1;
    }
}

int normal_fib(int n)
{
    if (n <= 1)
    {
        F[n] = n;
        return n;
    }
    else
    {
        if (F[n - 2] == -1)
        {
            F[n - 2] = normal_fib(n - 2);
        }
        if (F[n - 1] == -1)
        {
            F[n - 1] = normal_fib(n - 1);
        }
        return F[n - 2] + F[n - 1];
    }
}

void run()
{
    int n;
    int result1;
    int result2;
    int result3;

    cout << "Please enter number of terms: ";
    cin >> n;

    try
    {
        result3 = normal_fib(n);
        result2 = excessive_recursive_fib(n);
        result1 = loop_fib(n);
        cout << "Fibonacci Loop Result with " << n << " numbers: " << result1 << endl;
        cout << "Fibonacci Excessive Recursion Result with " << n << " numbers: " << result2 << endl;
        cout << "Fibonacci Normal Recursion Result with " << n << " numbers: " << result3 << endl;
    }
    catch (int &e)
    {
        std::cerr << e << " is an Invalid Number." << '\n';
    }
}

int main(void)
{
    initialize_array();
    run();

    return 0;
}