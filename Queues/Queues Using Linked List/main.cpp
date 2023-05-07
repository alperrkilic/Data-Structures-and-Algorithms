#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
} *front{nullptr}, *rear{nullptr};

void enqueue(int x)
{
    Node *t = new Node;

    if (t == nullptr)
    {
        cout << "Queue is Full!" << endl;
    }
    else
    {
        t->data = x;
        t->next = nullptr;
        if (front == nullptr)
        {
            front = rear = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue()
{
    int x = -1;
    struct Node *t;

    if (front == nullptr)
    {
        cout << "Queue is empty!" << endl;
    }
    else
    {
        x = front->data;
        t = front;
        front = front->next;
        delete t;
    }
    return x;
}

void display()
{
    struct Node *p = front;

    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main(void)
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    display();

    dequeue();

    display();

    return 0;
}