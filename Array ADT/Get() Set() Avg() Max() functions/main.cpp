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

int get(struct Array &arr, int &index)
{
    if (index >= 0 && index <= arr.length)
    {
        return arr.A[index];
    }
    else
    {
        throw "Index is not valid.";
    }
}

void set(struct Array &arr, int &index, int &x)
{
    if (index >= 0 && index <= arr.length)
    {
        arr.A[index] = x;
    }
    else
    {
        throw "Index is not valid.";
    }
}

// max min sum avg

int max(struct Array &arr)
{
    if (arr.length > 0)
    {
        int max = arr.A[0];
        for (int i = 0; i < arr.length; i++)
        {
            if (arr.A[i] > max)
            {
                max = arr.A[i];
            }
        }
        return max;
    }
    else
    {
        throw "Array is empty, cannot find maximum.";
    }
}

int min(struct Array &arr)
{
    if (arr.length > 0)
    {
        int min = arr.A[0];
        for (int i = 0; i < arr.length; i++)
        {
            if (arr.A[i] < min)
            {
                min = arr.A[i];
            }
        }
        return min;
    }
    else
    {
        throw "Array is empty, cannot find minimum.";
    }
}

int sum(struct Array &arr)
{
    if (arr.length > 0)
    {
        int sum{0};
        for (int i = 0; i < arr.length; i++)
        {
            sum = sum + arr.A[i];
        }
        return sum;
    }
    else
    {
        throw "Array is empty, cannot calculate sum.";
    }
}

int avg(struct Array &arr)
{
    if (arr.length > 0)
    {
        int sum{0};
        for (int i = 0; i < arr.length; i++)
        {
            sum = sum + arr.A[i];
        }
        return sum / arr.length;
    }
    else
    {
        throw "Array is empty, cannot calculate average.";
    }
}

void run()
{
    struct Array arr = {{2, 3, 4, 5, 6, 22, 16, 93}, 10, 8};
    int index;

    try
    {
        cout << "Please enter the index to get: ";
        cin >> index;
        int element = get(arr, index);
        cout << "Element in index " << index << " is: " << element << endl;
        display(arr);
        cout << "Max Element: " << max(arr) << endl;
        cout << "Min Element: " << min(arr) << endl;
        cout << "Sum: " << sum(arr) << endl;
        cout << "Average: " << avg(arr) << endl;
    }
    catch (const char *ex)
    {
        cout << ex;
    }
}

int main(void)
{
    run();

    return 0;
}