#include <iostream>

using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T> *next;
};

template <typename T>
Node<T> *first = nullptr; // global variable

template <typename T>
void create(T A[], int n)
{
    Node<T> *temp, *last;
    first<T> = new Node<T>;   // allocate space for the first node
    first<T>->data = A[0];    // assign first node to the 0'th element of the array
    first<T>->next = nullptr; // assign the next node to null
    last = first<T>;          // assign last node to first node

    for (int i = 1; i < n; i++)
    {
        temp = new Node<T>;   // allocate space for the temp node
        temp->data = A[i];    // data of the temp is i'th element of the array
        temp->next = nullptr; // temp->next = null since we don't know whether loop continue
        last->next = temp;    // last node now points to the temp node;
        last = temp;          // assign new last as the temp node;
    }
}

template <typename T>
void display(struct Node<T> *p)
{
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

template <typename T>
int count_node(struct Node<T> *p)
{
    int count = 0;
    while (p != nullptr)
    {
        count++;
        p = p->next;
    }
    return count;
}

template <typename T>
void insert(struct Node<T> *p, int index, T x)
{
    struct Node<T> *temp;

    if (index < 0 || index > count_node(first<T>))
    {
        return;
    }
    temp = new Node<T>;
    temp->data = x;

    if (index == 0) // insert to the head
    {
        temp->next = first<T>;
        first<T> = temp;
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

template <typename T>
void insert_in_sorted(struct Node<T> *p, T x)
{
    struct Node<T> *temp = nullptr;
    struct Node<T> *q = nullptr;

    temp = new Node<T>;
    temp->data = x;
    temp->next = nullptr;

    if (first<T> == nullptr)
    {
        first<T> = temp;
    }
    else
    {
        while (p != nullptr && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first<T>)
        {
            temp->next = first<T>;
            first<T> = temp;
        }
        else
        {
            temp->next = q->next;
            q->next = temp;
        }
    }
}

template <typename T>
T delete_node(struct Node<T> *p, int index)
{
    Node<T> *q = nullptr;
    T x;

    if (index < 1 || index > count_node(first<T>))
    {
        return -1;
    }

    if (index == 1) // if deleting first
    {
        q = first<T>;              // q points to the first
        x = first<T>->data;        // before deleting, store the value of the first
        first<T> = first<T>->next; // new first becomes the 2nd element so first will point to the next element
        delete q;                  // now we're done with the first element so delete q which was pointing to the first
        return x;
    }
    else // if deleting other elements
    {
        for (int i = 0; i < index - 1; i++)
        {
            q = p; // finally q points to the element that we want to remove from the index
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
        return x;
    }
}

int main()
{
    int B[] = {1, 2, 5, 6, 7, 8};
    create<int>(B, 6);

    // Inserting

    cout << "Before Inserting: ";
    display(first<int>);

    insert_in_sorted(first<int>, 4);

    cout << "\nAfter Inserting: ";
    display(first<int>);

    // Deleting

    cout << "\nBefore Deleting: ";
    display(first<int>);
    cout << "\nAfter Deleting 5'th element: ";
    delete_node(first<int>, 5);
    display(first<int>);
    return 0;
}
