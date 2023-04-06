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

int main()
{
    char A[] = {'A', 'B', 'C'};
    int B[] = {1, 2, 3, 4, 5, 6};

    // create<char>(A, 3);
    // display<char>(first<char>);

    create<int>(B, 6);
    cout << "Before Inserting: ";
    display<int>(first<int>);
    insert<int>(first<int>, 3, 8);
    cout << "\nAfter Inserting: ";
    display<int>(first<int>);

    return 0;
}
