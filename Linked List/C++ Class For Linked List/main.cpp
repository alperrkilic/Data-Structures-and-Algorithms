#include <iostream>

using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node<T> *next;
};

template <class T>
class LinkedList
{
private:
    Node<T> *first;

public:
    LinkedList() : first{nullptr} {}
    LinkedList(T A[], int n);
    ~LinkedList();

    void Display();
    void Insert(int index, T x);
    int Delete(int index);
    int Length();
    void find_middle();
};

template <class T>
LinkedList<T>::LinkedList(T A[], int n)
{
    Node<T> *last, *temp;
    int i = 0;

    this->first = new Node<T>;
    first->data = A[0];
    first->next = nullptr;
    last = first;

    for (i = 1; i < n; i++)
    {
        temp = new Node<T>;   // allocate space for the temp node
        temp->data = A[i];    // assign data of the array into temp->data
        temp->next = nullptr; // since this temp is the latest element it won't point to anywhere
        last->next = temp;    // previous lasts' next is now the latest element which is temp
        last = temp;          // assign new last
    }
}

template <class T>
LinkedList<T>::~LinkedList()
{
    Node<T> *p = first;

    while (first)
    {
        first = first->next;
        delete p;
        p = first;
    }
}

template <class T>
void LinkedList<T>::Display()
{
    Node<T> *p = first;

    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

template <class T>
void LinkedList<T>::Insert(int index, T x)
{
    Node<T> *temp, *p;
    p = first;

    if (index < 0 || index > Length())
    {
        return;
    }

    temp = new Node<T>;
    temp->data = x;
    temp->next = nullptr;

    if (index == 0)
    {
        temp->next = first;
        first = temp;
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

template <class T>
int LinkedList<T>::Delete(int index)
{
    Node<T> *p, *q = nullptr;
    int x = -1;

    if (index < 1 || index > Length())
    {
        throw "Index doesn't exist.";
    }

    if (index == 1)
    {
        p = first;           // p now holds the address of the first element
        first = first->next; // first now holds the address of the second element
        x = p->data;         // x holds the data of the first element
        delete p;            // delete p, p is nullptr
    }
    else
    {
        p = first;
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
    }

    return x;
}

template <class T>
int LinkedList<T>::Length()
{
    Node<T> *p = first;
    int length = 0;

    while (p != nullptr)
    {
        length++;
        p = p->next;
    }

    return length;
}

template <class T>
void LinkedList<T>::find_middle()
{
    /*
        Basically when q is moving 2 times and p is moving 1 time, when q becomes nullptr, p will be the middle node
    */

    Node<T> *p = first;
    Node<T> *q = first;

    while (q != nullptr)
    {
        q = q->next;
        if (q != nullptr)
        {
            q = q->next;
        }
        if (q != nullptr)
        {
            p = p->next;
        }
    }

    cout << "Middle Element is: " << p->data << endl;
}

int main()
{

    int A[] = {1, 2, 3, 4, 5};
    LinkedList<int> l(A, 5);

    l.Insert(0, 8);
    l.Display();

    l.find_middle();

    return 0;
}
