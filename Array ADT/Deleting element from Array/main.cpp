#include <iostream>
#include <stdio.h>

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

int delete_function(struct Array &arr, int index)
{
    int x = 0;

    if (index >= 0 && index <= arr.length - 1)
    {
        x = arr.A[index];
        for (int i = index; i < arr.length - 1; i++)
        {
            arr.A[i] = arr.A[i + 1];
        }
        arr.length--;
        return x;
    }
    else
    {
        throw "Invalid index or size.";
    }
}

void run()
{
    struct Array arr = {{2, 3, 4, 5, 6, 7, 11}, 10, 7};

    int index;

    display(arr);
    cout << "Please enter the index to be deleted from the array: ";
    cin >> index;

    try
    {
        cout << delete_function(arr, index) << " is successfully deleted from the array." << endl;
    }
    catch (char const *ex)
    {
        cout << ex;
    }

    cout << "New array is: " << endl;
    display(arr);
}

int main(void)
{
    run();

    return 0;
}