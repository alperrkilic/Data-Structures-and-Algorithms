#include <iostream>
#include <stdio.h>

using namespace std;

int main(void)
{

    int array[5];

    array[0] = 12;
    array[1] = 15;
    array[2] = 25;

    cout << sizeof(array) << endl;
    cout << array[1] << endl;

    int A[10] = {0}; // all elements are initialized to zero

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", A[i]);
    }

    std::cout << "\n--------------------" << std::endl;

    for (auto x : A)
    {
        cout << x << " ";
    }

    return 0;
}