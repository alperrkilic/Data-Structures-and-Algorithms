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

int main(void)
{
    int A[] = {2, 3, 4, 5, 6};

    create(A, 5);

    display(head);
    recursive_display(head);

    return 0;
}