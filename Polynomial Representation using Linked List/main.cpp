#include <iostream>
#include <math.h>

using namespace std;

struct Node
{
    int coeff;
    int exp;
    Node *next;
} *poly = nullptr;

void create()
{
    Node *t, *last;
    int num;

    printf("Enter number of terms: ");
    scanf("%d", &num);
    printf("Enter each term with coefficient and exponent:\n");

    for (int i = 0; i < num; i++)
    {
        t = new Node;
        scanf("%d %d", &t->coeff, &t->exp);
        t->next = nullptr;
        if (poly == nullptr)
        {
            poly = last = t;
        }
        else
        {
            last->next = t; // this last is the previous last and new last will become t
            last = t;
        }
    }
}

double evaluate(struct Node *p, int x)
{
    double val{0};

    while (p != nullptr)
    {
        val += p->coeff * pow(x, p->exp);
        p = p->next;
    }
    return val;
}

void display(struct Node *p)
{
    while (p != nullptr)
    {
        printf("%dx^%d ", p->coeff, p->exp);
        if (p->next != nullptr)
        {
            printf(" + ");
        }
        p = p->next;
    }
    printf("\n");
}

int main(void)
{
    create();
    display(poly);

    auto x = evaluate(poly, 2);
    cout << "P(2) is: " << x;

    return 0;
}