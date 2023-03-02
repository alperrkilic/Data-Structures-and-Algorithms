#include <iostream>

using namespace std;

void add(int &a, int &b, int &c)
{
    c = a + b;
}

void Subtract(int &a, int &b, int *ptr) // a and b is called by reference in this example
{
    *ptr = a - b;
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main(void)
{
    int num1 = 10, num2 = 15, sum;
    int *subtract = new int; // should point somewhere otherwise, just initialize it as normal integer and send its reference to the function

    add(num1, num2, sum);

    Subtract(num1, num2, subtract);

    cout << "Sum: " << sum << endl;
    cout << "Subtract: " << *subtract << endl;

    // Swap Function

    cout << "----------------------------" << endl;

    int a = 10;
    int b = 20;

    cout << "Before swapping a: " << a << endl;
    cout << "Before swapping b: " << b << endl;

    swap(&a, &b);

    cout << "After swapping a: " << a << endl;
    cout << "After swapping b: " << b << endl;

    return 0;
}

// When you don't have to modify actual parameters, you can use pass by value