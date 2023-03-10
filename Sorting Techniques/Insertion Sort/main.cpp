#include <iostream>
#include <stdio.h>

using namespace std;

void insertionSort(int A[], int n)
{
    int i, j, x;

    for (i = 1; i < n; i++)
    {
        j = i - 1;
        x = A[i];
        while (j > -1 && A[j] > x)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
    }
}

void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main(void)
{

    int A[] = {11, 13, 7, 2, 6, 9, 4, 5, 10, 3}, n = 10, i;

    insertionSort(A, n);
    printArray(A, n);

    return 0;
}