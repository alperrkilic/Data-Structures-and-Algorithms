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

void Union(struct Array &arr1, struct Array &arr2, struct Array &arr3)
{

    int i, j, k;
    i = j = k = 0;

    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
        {
            arr3.A[k++] = arr1.A[i++];
        }
        else if (arr2.A[j] < arr1.A[i])
        {
            arr3.A[k++] = arr2.A[j++];
        }
        else
        {
            arr3.A[k++] = arr1.A[i++]; // if they are equal i and j must continue
            j++;                       // and element must be copied once
        }
    }

    for (; i < arr1.length; i++)
    {
        arr3.A[k++] = arr1.A[i]; // i iterates the first array
    }

    for (; j < arr2.length; j++)
    {
        arr3.A[k++] = arr2.A[j];
    }

    arr3.length = k;
    arr3.size = 10;
}

void intersection(struct Array &arr1, struct Array &arr2, struct Array &arr3)
{
    // in this method we have to copy the elements if and only if the element is
    // found both in arr1 and arr2, with the same logic of merging, i will iterate first array
    // j will iterate second array and k will iterate the newly generated array
    int i, j, k;
    i = j = k = 0;

    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
        {
            i++;
        }
        else if (arr2.A[j] < arr1.A[i])
        {
            j++;
        }
        else
        {
            arr3.A[k++] = arr1.A[i++];
            j++;
        }
    }

    arr3.length = k;
    arr3.size = 10;
}

void difference(struct Array &arr1, struct Array &arr2, struct Array &arr3)
{
    // supposing arr1 and arr2 are sorted
    // in this method we are trying to find the elements that exist in arr1 and does not exist in arr2
    // after we find these elements we will store them into arr3. Similarly, i iterates arr1, j iterates arr2,
    // and k iterates arr3
    int i, j, k;
    i = j = k = 0;

    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
        {
            arr3.A[k++] = arr1.A[i++];
        }
        else if (arr2.A[j] < arr1.A[i])
        {
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }

    for (; i < arr1.length; i++)
    {
        arr3.A[k++] = arr1.A[i];
    }

    arr3.length = k;
    arr3.size = 10;
}

int main(void)
{
    struct Array arr1 = {{2, 6, 10, 15, 25}, 10, 5};
    struct Array arr2 = {{3, 6, 7, 15, 20}, 10, 5};
    struct Array UnionArray;
    struct Array IntersectArray;
    struct Array differenceArray;

    cout << "Union Array: ";
    Union(arr1, arr2, UnionArray);
    display(UnionArray);

    cout << endl;

    cout << "Intersection Array: ";
    intersection(arr1, arr2, IntersectArray);
    display(IntersectArray);

    cout << endl;

    cout << "Difference Array: ";
    difference(arr1, arr2, differenceArray);
    display(differenceArray);

    return 0;
}