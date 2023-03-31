#include <iostream>

using namespace std;

int main(void)
{
    return 0;
}

/*
    Normal MATRIX:

    a11 a12 a13 a14 a15
    a21 a22 a23 a24 a25
    a31 a32 a33 a34 a35
    a41 a42 a43 a44 a45
    a51 a52 a53 a54 a55

    UPPER TRIANGULAR MATRIX:

    a11 a12 a13 a14 a15
     0  a22 a23 a24 a25
     0   0  a33 a34 a35
     0   0   0  a44 a45
     0   0   0   0  a55


    M[i,j] = 0 if i>j
    M[i,j] = nonzero if i<=j

    nonzero : 5 + 4 + 3 + 2 + 1 = n + n-1 + n-2 + ... 1  = n*(n+1)/2

    Row-Major:

    A | a11 a12 a13 a14 a15 | a22 a23 a24 a25 | a33 a34 a35 | a44 a45 | a55  |
      |       row1          |       row2      |     row3    |  row4   | row5 |


    Access Index : A(4,5) = [5+4+3] + 1
    Access Index : A(i,j) = [n + n-1 + n-2 ... + n-(i-2)] + j-i


    Column Major:

    A| a11 | a12 a22 | a13 a23 a33 | a14 a24 a34 a44 | a15 a25 a35 a45 a55 |
     | col1|  col2   |     col3    |       col4      |        col5         |


    Access Index : A(4,5) = [1 + 2 + 3 + 4] + 3
    Access Index : A(i,j) = [1 + 2 + 3 + ... + j-1] + (i-1)

*/