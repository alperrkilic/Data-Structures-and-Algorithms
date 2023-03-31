#include <iostream>

using namespace std;

struct Matrix
{
    int A[10];
    int n; // number of diagonals which will determine the size of the matrix
};

void Set(struct Matrix &m, int i, int j, int x)
{
    if (i == j)
    {
        m.A[i - 1] = x;
    }
}

int Get(struct Matrix m, int i, int j)
{
    if (i == j)
    {
        return m.A[i - 1];
    }
    else
    {
        return -1;
    }
}

void Display(struct Matrix m)
{
    int i;

    for (int i = 0; i < m.n; i++)
    {
        for (int j = 0; j < m.n; j++)
        {
            if (i == j)
            {
                cout << m.A[i] << " ";
            }
            else
            {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}

int main(void)
{
    struct Matrix m;
    m.n = 4;

    Set(m, 1, 1, 5);
    Set(m, 2, 2, 8);
    Set(m, 3, 3, 9);
    Set(m, 4, 4, 12);

    Display(m);

    return 0;
}

/*
    What is the Point of the Diagonal Matrix?

    Diagonal Matrix only contains its nonzero elements when i = j

    1 0 0 0
    0 1 0 0
    0 0 1 0
    0 0 0 1

    Above you can see a diagonal matrix, so if we know that it is a diagonal matrix
    then why don't we just store the number of diagonal elements and
    their values. By that, we can save n^2 - n spaces.

*/