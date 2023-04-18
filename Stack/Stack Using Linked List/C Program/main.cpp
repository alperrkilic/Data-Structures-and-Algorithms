#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
} *top = nullptr;

void push(int x)
{
    struct Node *t;
    t = new Node;

    if (t == nullptr)
    {
        cout << "Stack is Full" << endl;
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop()
{
    Node *t;
    int x = -1;

    if (top == nullptr)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}

void display()
{
    struct Node *p;
    p = top;

    while (p != nullptr)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(void)
{

    push(10);
    push(20);
    push(30);
    display();

    return 0;
}