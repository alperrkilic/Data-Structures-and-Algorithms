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

void insertElement(struct Array &arr, int &x)
{
    int i = arr.length - 1;

    while (arr.A[i] > x)
    {
        arr.A[i + 1] = arr.A[i];
        i--;
    }
    arr.A[i + 1] = x;
    arr.length++;
}

bool isSorted(struct Array &arr)
{
    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1]) // checking consecutive elements
        {
            return false;
        }
    }
    return true;
}

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void negativePositiveSort(struct Array &arr)
{
    int i = 0, j = arr.length - 1;

    while (i < j)
    {
        while (arr.A[i] < 0)
        {
            i++;
        }
        while (arr.A[j] >= 0)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr.A[i], arr.A[j]);
        }
    }
}

void run()
{
    struct Array arr = {{2, -3, 25, 10, -15, -7}, 10, 6};

    cout << boolalpha;
    int x = 12;
    insertElement(arr, x);

    display(arr);
    cout << "Is array sorted: " << isSorted(arr) << endl;
    negativePositiveSort(arr);
    display(arr);
}

int main(void)
{

    run();

    return 0;
}