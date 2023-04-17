#include <iostream>

using namespace std;

struct Stack
{
    int size;
    int top;
    int *s;
};

void create(struct Stack *st)
{
    printf("Please enter the size: ");
    scanf("%d", &st->size);
    st->top = -1;
    st->s = new int[st->size];
}

void display(struct Stack *st)
{
    for (int i = st->top; i >= 0; i--)
    {
        printf("%d ", st->s[i]);
    }
    printf("\n");
}

void push(struct Stack *st, int x)
{
    if (st->top == st->size - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}

int pop(struct Stack *st)
{
    int x = -1;

    if (st->top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        x = st->s[st->top];
        st->top--;
    }
    return x;
}

int peek(struct Stack *st, int index)
{
    int x = -1;
    if (st->top - index < 0)
    {
        printf("Invalid index\n");
    }
    x = st->s[st->top - index + 1];
    return x;
}

bool isEmpty(struct Stack *st)
{
    if (st->top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull(struct Stack *st)
{
    return (st->top == st->size - 1);
}

int stackTop(struct Stack *st)
{
    if (!isEmpty(st))
    {
        return st->s[st->top];
    }
    return -1;
}

int main(void)
{
    struct Stack st;

    create(&st);

    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    push(&st, 50);

    printf("%d \n", pop(&st));
    printf("%d \n", peek(&st, 1));

    display(&st);

    return 0;
}