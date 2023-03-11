#include <iostream>
#include <stdio.h>

using namespace std;

void swap(int &x, int &y)
{
    int temp;
    temp = y;
    y = x;
    x = temp;
}

void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void selectionSort(int A[], int n)
{
    int j, k, i;
    for (i = 0; i < n; i++)
    {
        k = i;
        for (j = i; j < n; j++)
        {
            if (A[j] < A[k])
            {
                k = j;
            }
        }
        swap(A[i], A[k]);
    }
}

int main(void)
{

    int A[] = {11, 13, 7, 2, 6, 9, 4, 5, 19, 3}, n = 10;

    selectionSort(A, 10);
    printArray(A, 10);

    return 0;
}