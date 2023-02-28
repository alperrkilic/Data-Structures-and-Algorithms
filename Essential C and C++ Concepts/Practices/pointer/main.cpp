#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(void)
{
    // C syntax:
    // int *p;
    // p = (int *)malloc(5 * sizeof(int));
    // printf("%d\n----------------\n", sizeof(p));

    int a = 10;

    int *pointer;

    pointer = &a;

    printf("using pointer %d", *pointer);
    printf("\npointer holding address: %d", pointer);
    printf("\nAddress of variable 'a': %d", &a);
    printf("\n--------------------\n");

    int A[5] = {2, 4, 6, 8, 10};
    int *p;

    p = A;

    printf("\n%d\n", p);

    for (int i = 0; i < 5; i++)
    {
        cout << p[i] << " ";
    }

    cout << endl;

    // C++ Syntax:

    int *point = new int[5];

    for (int i = 0; i < 5; i++)
    {
        point[i] = i;
        cout << point[i] << " ";
    }

    int *p1;
    char *p2;
    float *p3;
    double *p4;

    cout << endl
         << sizeof(p1) << endl;
    cout << sizeof(p2) << endl;
    cout << sizeof(p3) << endl;
    cout << sizeof(p4) << endl;

    delete[] point; // C++ syntax
    // free(p); C language syntax

    return 0;
}