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

int linearSearch(struct Array &arr, int key)
{
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] == key)
        {
            return i;
        }
    }
    return -1;
}

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int improvedLinearSearch(struct Array &arr, int key) // Transposition Method
{
    for (int i = 0; i < arr.length; i++)
    {
        if (key == arr.A[i] && i >= 1)
        {
            swap(arr.A[i], arr.A[i - 1]);
            return i - 1;
        }
    }
    return -1;
}

int main(void)
{
    struct Array arr = {{21, 1, 16, 8, 3, 5, 8, 9, 6, 4}, 10, 10};

    int key;
    cout << "Please enter the element you search: ";
    cin >> key;
    int result = linearSearch(arr, key);

    if (result == -1)
    {
        cout << "Element is not found." << endl;
    }
    else
    {
        cout << "The element is found at index: " << result << endl;
    }

    return 0;
}