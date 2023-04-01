#include <iostream>
#include <stdio.h>

using namespace std;

struct Element
{
    int i;
    int j;
    int x;
};

struct Sparse
{
    int m;
    int n;
    int num;
    struct Element *e;
};

void Create(struct Sparse *s)
{
    printf("Enter Dimensions: ");
    scanf("%d %d", &s->m, &s->n);
    printf("Enter number of nonzero elements: ");
    scanf("%d", &s->num);
    s->e = new Element[s->num];
    printf("Enter all Elements\n");

    for (int i = 0; i < s->num; i++)
    {
        scanf("%d %d %d", &s->e[i].i, &s->e[i].j, &s->e[i].x);
    }
}

void display(struct Sparse &s)
{
    int i, j, k = 0;

    for (i = 0; i < s.m; i++)
    {
        for (j = 0; j < s.n; j++)
        {
            if (i == s.e[k].i && j == s.e[k].j)
            {
                printf("%d ", s.e[k++].x);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

struct Sparse *add(struct Sparse *s1, struct Sparse *s2)
{
    struct Sparse *sum;
    int i, j, k;
    i = j = k = 0;

    sum = new Sparse;
    sum->e = new Element[s1->num + s2->num];

    while (i < s1->num && j < s2->num)
    {
        if (s1->e[i].i < s2->e[j].i) // compare row numbers
        {
            sum->e[k++] = s1->e[i++];
        }
        else if (s1->e[i].i > s2->e[j].i)
        {
            sum->e[k++] = s2->e[j++];
        }
        else // if row numbers are equal it will enter to else part
        {
            if (s1->e[i].j < s2->e[j].j)
            {
                sum->e[k++] = s1->e[i++];
            }
            else if (s1->e[i].j > s2->e[j].j)
            {
                sum->e[k++] = s2->e[j++];
            }
            else
            {
                sum->e[k] = s1->e[i];
                sum->e[k++].x = s1->e[i++].x + s2->e[j++].x;
            }
        }
    }

    for (; i < s1->num; i++)
        sum->e[k++] = s1->e[i];

    for (; j < s2->num; j++)
        sum->e[k++] = s2->e[j++]; // fixed indexing here

    sum->m = s1->m;
    sum->n = s1->n;
    sum->num = k;

    return sum;
}

int main(void)
{

    // struct Sparse s;

    // Create(&s);

    // cout << endl;

    // display(s);

    cout << endl
         << "Addition of Two Matrices: " << endl;

    struct Sparse s1, s2, *s3;

    Create(&s1);
    Create(&s2);

    s3 = add(&s1, &s2);
    printf("First Matrix\n");
    display(s1);
    printf("\nSecond Matrix\n");
    display(s2);
    printf("\nSum Matrix\n");
    display(*s3);

    return 0;
}

/*
    Sparse Matrix is a matrix that the most of the elements
    are  0's. There are very few nonzero elements

     0  0  0  0  0   0   0  3  0
     0  0  8  0  0   10  0  0  0
     0  0  0  0  0   0   0  0  0
     4  0  0  0  0   0   0  0  0
     0  0  0  0  0   0   0  0  0
     0  0  2  0  0   0   0  0  0
     0  0  0  6  0   0   0  0  0
     0  9  0  0  5   0   0  0  0

                8 X 9


    72x4 = 288 bytes


    ROW | COLUMN | ELEMENT
    ----------------------
     1  |   8    |   3
     2  |   3    |   8
     4  |   1    |   4
     6  |   3    |   2
     7  |   4    |   6
     8  |   2    |   9
     8  |   5    |   5

    A[3,8,10,4,2,6,9,5]
   IA[0,1,3,3,4,4,5,6,8] // cumulative number of nonzero elements
     JA[8,3,6,1,3,4,2,5] // column number

    8 + 9 + 8 = 25 elements -> 100 bytes

*/