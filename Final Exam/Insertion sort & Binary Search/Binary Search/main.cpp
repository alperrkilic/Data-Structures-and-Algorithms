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

int main(void)
{
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};

    // run_normal(arr);

    return 0;
}