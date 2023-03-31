#include <iostream>

using namespace std;

class Lower_Triangular
{
private:
    int *A;
    int n;

public:
    Lower_Triangular();
    Lower_Triangular(int n);
    ~Lower_Triangular();

    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    int GetDimension() { return n; }
};

void Lower_Triangular::Set(int i, int j, int x)
{
    if (i >= j)
    {
        this->A[i * (i - 1) / 2 + j - 1] = x;
    }
}

int Lower_Triangular::Get(int i, int j)
{
    if (i >= j)
    {
        return this->A[i * (i - 1) / 2 + j - 1];
    }
    return 0;
}

void Lower_Triangular::Display()
{
    for (int i = 1; i <= this->n; i++)
    {
        for (int j = 1; j <= this->n; j++)
        {
            if (i >= j)
            {
                cout << this->A[i * (i - 1) / 2 + j - 1] << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

Lower_Triangular::Lower_Triangular()
{
    this->n = 2;
    this->A = new int[2 * (2 + 1) / 2];
}

Lower_Triangular::Lower_Triangular(int n)
{
    this->n = n;
    this->A = new int[n * (n + 1) / 2];
}

Lower_Triangular::~Lower_Triangular()
{
    delete[] A;
}

int main(void)
{
    int dimension;

    cout << "Enter Dimensions: ";
    cin >> dimension;

    Lower_Triangular lower_triangular_matrix(dimension);

    int x;
    cout << "Enter All Elements" << endl;

    for (int i = 1; i <= dimension; i++)
    {
        for (int j = 1; j <= dimension; j++)
        {
            cin >> x;
            lower_triangular_matrix.Set(i, j, x);
        }
    }

    cout << endl;

    lower_triangular_matrix.Display();

    return 0;
}

/*
    Normal MATRIX:

    a11 a12 a13 a14 a15
    a21 a22 a23 a24 a25
    a31 a32 a33 a34 a35
    a41 a42 a43 a44 a45
    a51 a52 a53 a54 a55

    LOWER TRIANGULAR MATRIX:

    a11  0   0   0   0
    a21 a22  0   0   0
    a31 a32 a33  0   0
    a41 a42 a43 a44  0
    a51 a52 a53 a54 a55

    M[i,j] = 0 if i<j
    M[i,j] = nonzero if i>=j

    nonzero : 1+2+3+..+n = n(n+1) / 2
    zero    : n^2 - n(n+1) / 2

    Row Major Lower Triangle:

    A| a11 | a21 a22 | a31 a32 a33 | a41 a42 a43 a44 | a51 a52 a53 a54 a55|
      row1 |  row 2  |  row 3      |      row4       |       row5         |


    Access Index : A[4,3] = [1+2+3] + 2 = 8
    Access Index : A[5,4] = [1+2+3+4] + 3 = 13

    So the formula is : A[i,j] = i(i-1) /2 + j-1


    Column Major Lower Triangle:

    A | a11 a21 a31 a41 a51 | a22 a32 a42 a52 | a33 a43 a53 | a44 a54 | a55  |
      |        col1         |       col2      |     col3    |   col4  | col5 |

    n x n = 25 --> n = 5

    Access Index : A[4,4] = [5 + 4 + 3] + 0 = 12
    Access Index : A[5,4] = [5 + 4 + 3] + 1 = 13
    Access Index : A[5,3] = [5 + 4] + 2 = 11

    So the formula is : A[i,j] = [n + n-1 + n-2 + n-(j-2)] + (i-j)

*/