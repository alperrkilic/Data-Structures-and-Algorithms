#include <iostream>

using namespace std;

int main(void)
{
    return 0;
}

/*
    TRI-DIAGONAL MATRIX:

    a11 a12  0   0   0
    a21 a22 a23  0   0
    0   a32 a33 a34  0
    0    0  a43 a44 a45
    0    0   0  a54 a55

    Main  Diagonal i-j =  0
    Lower Diagonal i-j =  1
    Upper Diagonal i-j = -1

    Generally : |i-j| <= 1

    M[i,j] = nonzero if |i-j|<=1
    M[i,j] = 0 if |i-j| > 1

    5 + 4 + 4 --> n + n-1 + n-1 --> 3n-2

    A | a21 a32 a43 a54 | a11 a22 a33 a44 a55 | a12 a23 a34 a45 |
      |     lower diag. |     main diag.      |   upper diag.   |


    Index(i,j)

        case 1 : if i-j = 1  index = i-2
        case 2 : if i-j = 0  index = n-1+i-2
        case 3 : if i-j = -1 index = 2n-1+i-1

*/