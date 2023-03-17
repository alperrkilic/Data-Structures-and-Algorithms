#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array &arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}

void Append(struct Array &arr, int x) // adds an element add the end of the array
{
    if (arr.length < arr.size)
    {
        arr.A[arr.length++] = x;
    }
    else
    {
        throw "There was en error with the size.";
    }
}

void insert(struct Array &arr, int index, int x)
{
    if (index >= 0 && index <= arr.length)
    {
        for (int i = arr.length; i > index; i--)
        {
            arr.A[i] = arr.A[i - 1];
        }
        arr.A[index] = x;
        arr.length++;
    }
    else
    {
        throw "There was en error with the size.";
    }
}

int main(void)
{
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};

    int index;
    int value;

    cout << "Please enter the value and the index: ";
    cin >> value >> index;

    try
    {
        insert(arr, index, value);
        Display(arr);
    }
    catch (char const *ex)
    {
        cout << ex;
    }

    return 0;
}