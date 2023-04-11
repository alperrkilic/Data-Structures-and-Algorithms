#include <iostream>
#include <stdio.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *head;

void create(int A[], int n)
{
    int i;
    struct Node *temp, *last;
    head = new Node;
    head->data = A[0]; // assign data for the head node
    head->next = head; // head points to the head since we don't know how many elements are there
    last = head;       // last node is head node since we're just defining the first element

    for (i = 1; i < n; i++) // we've declared first element therefore starts from 1
    {
        temp = new Node;         // allocate new space for temp node which will hold every node for linked list and will be initialized continuously in the loop
        temp->data = A[i];       // assign temp->data from i'th element of the array
        temp->next = last->next; // temp->next is now last->next which was head which means second node's next is the last node.
        last->next = temp;       // initially last was head, last->next will be the second node meaning that A[0] -> A[1]
        last = temp;             // new last is the latest element which is temp
    }

    /*
        basically when initializing:

        |-----.
        A[0]--|     (A is pointing itself)

        in the loop:

        |-------------.
        A[0] -> A[i]--| (every time it goes back to the head node and we obtain circular linked list)

    */
}

void display(struct Node *h)
{
    do
    {
        printf("%d ", h->data);
        h = h->next;
    } while (h != head);
    printf("\n");
}

void recursive_display(struct Node *h)
{
    static int flag = 0;

    if (h != head || flag == 0)
    {
        flag = 1;
        printf("%d ", h->data);
        recursive_display(h->next);
    }
    flag = 0;
    cout << endl;
}

int Length(struct Node *p)
{
    int len = 0;

    do
    {
        if (p)
        {
            len++;
            p = p->next;
        }
    } while (p->next != head);

    return len;
}

void insert_node(struct Node *p, int index, int x)
{

    if (index < 0 || index > Length(p))
    {
        return;
    }

    Node *temp = new Node;
    temp->data = x;

    if (index == 0) // inserting before head node
    {
        if (head == nullptr) // if head node does not exist which means we don't have any node
        {
            head = temp;
            head->next = head;
        }
        else
        {
            while (p->next != head)
            {
                p = p->next; // last element will be p now
            }
            p->next = temp;
            temp->next = head;
            head = temp;
        }
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        temp->next = p->next;
        p->next = temp;
    }
}

int delete_node(struct Node *p, int index)
{
    int x;

    if (index <= 0 || p == nullptr)
    {
        return -1;
    }

    if (index == 1)
    {
        if (head == head->next) // if there's only one node
        {
            x = head->data;
            delete head;
            head = nullptr;
        }
        else
        {
            while (p->next != head) // if there's more than one node and we're trying to delete head node
            {
                p = p->next;
            }
            p->next = head->next;
            x = head->data;
            delete head;
            head = p->next;
        }
    }
    else // deleting from a specific place
    {
        struct Node *q;

        for (int i = 0; i < index - 2; i++)
        {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        x = q->data;
        delete q;
    }

    return x;
}

int main(void)
{
    int A[] = {2, 3, 4, 5, 6};

    create(A, 5);

    delete_node(head, 5);

    display(head);

    return 0;
}