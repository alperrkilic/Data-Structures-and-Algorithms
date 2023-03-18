#include <iostream>

using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

void display(struct Array &arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << " ";
    }
    cout << endl;
}

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void reverseArraySwap(struct Array &arr)
{
    int k = arr.length - 1;

    for (int i = 0; i < k; i++)
    {
        swap(arr.A[i], arr.A[k]);
        k--;
    }
}

int main(void)
{
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};

    cout << "Before reversing: ";
    display(arr);
    reverseArraySwap(arr);
    cout << "After reversing: ";
    display(arr);

    return 0;
}