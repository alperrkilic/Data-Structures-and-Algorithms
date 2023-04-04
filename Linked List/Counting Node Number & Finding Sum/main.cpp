#include <iostream>
#include <stdio.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first{nullptr}; // first becomes a global pointer

void create(int A[], int n)
{
    int i;
    struct Node *temp, *last;

    first = new Node;
    first->data = A[0];    // data of the first linked list is 3
    first->next = nullptr; // first node does not point any other node
    last = first;          // initializing last as the first

    for (int i = 1; i < n; i++)
    {
        temp = new Node;      // allocating space from heap for temp node
        temp->data = A[i];    // temp->data = A[i] holds the value
        temp->next = nullptr; // since we don't know whether the condition stops, temp->next must be nullptr
        last->next = temp;    // now the previous last node points to temp
        last = temp;          // new last becomes temp
    }
}

void Display(struct Node *p) // we should pass first node
{
    while (p != nullptr)
    {
        printf("%d ", p->data);
        p = p->next; // current node now points the next node
    }
}

void RecursiveDisplay(struct Node *p)
{
    if (p != nullptr)
    {
        printf("%d ", p->data);
        RecursiveDisplay(p->next);
    }
}

void ReverseRecursiveDisplay(struct Node *p)
{
    if (p != nullptr)
    {
        ReverseRecursiveDisplay(p->next);
        printf("%d ", p->data);
    }
}

int CountNode(struct Node *p)
{
    int count{0};

    while (p != nullptr)
    {
        count++;
        p = p->next;
    }

    return count;
}

int RecursiveCountNode(struct Node *p)
{
    if (p == nullptr)
    {
        return 0;
    }
    else
    {
        return RecursiveCountNode(p->next) + 1;
    }
}

int Add(struct Node *p)
{
    int sum = 0;
    while (p != nullptr)
    {
        sum = sum + p->data;
        p = p->next;
    }

    return sum;
}

int RecursiveSum(struct Node *p)
{
    if (p == nullptr)
    {
        return 0;
    }
    else
    {
        return RecursiveSum(p->next) + p->data;
    }
}

int main(void)
{
    int A[] = {3, 5, 7, 10, 15};

    create(A, 5); // creating linked list
    cout << "\nNormally Displaying Linked List: ";
    Display(first); // displaying linked list
    cout << "\nRecursive Displaying Linked List: ";
    RecursiveDisplay(first);
    cout << "\nReverse Recursive Displaying Linked List: ";
    ReverseRecursiveDisplay(first);

    int nodeNum{0};
    nodeNum = CountNode(first);
    cout << "\nNumber of nodes: " << nodeNum << endl;

    int nodeSum{0};
    nodeSum = Add(first);
    cout << "\nSummation of nodes is: " << nodeSum << endl;

    return 0;
}