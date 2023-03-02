#include <iostream>

using namespace std;

void function(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
}

void function2(int *A, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
}

int main(void)
{
    int A[5] = {2, 4, 6, 8, 10};

    cout << "First Function" << endl;
    function(A, 5);

    cout << "\nSecond Function" << endl;
    function2(A, 5);

    return 0;
}
