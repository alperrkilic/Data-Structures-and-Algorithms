#include <iostream>

using namespace std;

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *first = nullptr;

void create_list(int A[], int n)
{
    Node *temp;
    Node *last;

    first = new Node;
    first->data = A[0];
    first->prev = nullptr;
    first->next = nullptr;
    last = first;

    for (int i = 1; i < n; i++)
    {
        temp = new Node;
        temp->data = A[i];
        temp->next = last->next;
        temp->prev = last;
        last->next = temp;
        last = temp;
    }
}

void display_list(struct Node *p)
{
    while (p != nullptr)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int list_length(struct Node *p)
{
    int length{0};

    while (p != nullptr)
    {
        length++;
        p = p->next;
    }
    return length;
}

void insert_node(struct Node *p, int index, int x)
{
    struct Node *t;

    if (index < 0 || index > list_length(p))
    {
        return;
    }

    if (index == 0)
    {
        t = new Node;
        t->data = x;
        t->prev = nullptr;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t = new Node;
        t->data = x;

        t->prev = p;
        t->next = p->next;

        if (p->next != nullptr)
        {
            (p->next)->prev = t;
        }
        p->next = t;
    }
}

int delete_node(struct Node *p, int index)
{
    struct Node *q;
    int x = -1;

    if (index < 1 || index > list_length(p))
    {
        return -1;
    }

    if (index == 1)
    {
        first = first->next;
        if (first != nullptr)
        {
            first->prev = nullptr;
        }

        x = p->data;
        delete p;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }

        (p->prev)->next = p->next;

        if (p->next)
        {
            (p->next)->prev = p->prev;
        }

        x = p->data;
        delete p;
    }

    return x;
}

void reverse_circular(struct Node *p)
{
    struct Node *temp;

    while (p != nullptr)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;

        if (p != nullptr && p->next == nullptr)
        {
            first = p;
        }
    }
}

int main(void)
{
    int A[] = {10, 20, 30, 40, 50};
    create_list(A, 5);
    display_list(first);
    cout << "Length of the list is: " << list_length(first) << endl;

    insert_node(first, 2, 25);
    display_list(first);
    cout << "\nLength of the list is: " << list_length(first) << endl;

    cout << "Deleting 4'th Node (" << delete_node(first, 4) << "): ";

    display_list(first);

    cout << "After reversing the Linked List: ";
    reverse_circular(first);
    display_list(first);

    return 0;
}