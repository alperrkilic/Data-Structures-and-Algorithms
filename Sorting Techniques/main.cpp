#include <iostream>
#include <stdio.h>

using namespace std;

void swapElements(int &x, int &y)
{
    int temp;
    temp = y;
    y = x;
    x = temp;
}

void bubbleSort(int A[], int n)
{
    int flag{0};

    for (int i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                swapElements(A[j], A[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
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

    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2}, n = 10;

    bubbleSort(A, n);
    printArray(A, n);

    return 0;
}