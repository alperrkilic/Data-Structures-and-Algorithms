#include <iostream>

using namespace std;

int main(void)
{
    return 0;
}

/*
    TOEPLITZ MATRIX

    2  3  4  5  6
    7  2  3  4  5
    8  7  2  3  4
    9  8  7  2  3
    10 9  8  7  2

    If you observe on each diagonal, elements are same

    M[i,j] = M[i-1 , j-1]

    How do we store these elements?

    we can just store the first column and the first row

    Element - n + n-1

    A | 2 3 4 5 6 | 7 8 9 10 |
      |   row     |    col   |


    Index (A[i,j])
        case 1: if i<=j // upper triangular
            A[2][4] -> 4-2 = 2
            A[3][4] -> 4-3 = 1
            Index : j-i

        case 2: if i>j
            Index : n + i - j -1




*/