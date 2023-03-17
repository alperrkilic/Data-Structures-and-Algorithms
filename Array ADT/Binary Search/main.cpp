#include <iostream>
#include <math.h>

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
}

int BinarySearch(struct Array &arr, int key)
{
    int low, mid, high;
    low = 0;
    high = arr.length - 1;

    while (low <= high)
    {
        mid = floor(low + high) / 2;
        if (key == arr.A[mid])
        {
            return mid;
        }
        else if (key < arr.A[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int RecursiveBinarySearch(int A[], int l, int h, int key)
{
    int mid;

    if (l <= h)
    {
        mid = (l + h) / 2;
        if (key == A[mid])
        {
            return mid;
        }
        else if (key < A[mid])
        {
            return RecursiveBinarySearch(A, l, mid - 1, key);
        }
        else
        {
            return RecursiveBinarySearch(A, mid + 1, h, key);
        }
    }

    return -1;
}

void check(int result)
{
    if (result < 0)
    {
        cout << "Element is not found." << endl;
    }
    else
    {
        cout << "Element is found at index: " << result;
    }
}

void run_normal(struct Array &arr)
{
    int key;
    cout << "Please enter the element you want to search for: ";
    cin >> key;

    int result = BinarySearch(arr, key);

    check(result);
}

void run_recursive(struct Array &arr)
{
    int key;
    cout << "Please enter the element you want to search for: ";
    cin >> key;

    int result = RecursiveBinarySearch(arr.A, 0, arr.length, 5);

    check(result);
}

int main(void)
{
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};

    // run_normal(arr);
    run_recursive(arr);

    return 0;
}