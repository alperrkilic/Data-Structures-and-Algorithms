#include "queue.h"

Queue::Queue() : front{-1}, rear{-1}, size{10}
{
    this->Q = new Node *[size];
}

Queue::Queue(int size) : front{-1}, rear{-1}, size{size}
{
    this->Q = new Node *[size];
}

void Queue::enqueue(Node *x)
{
    if (this->rear == this->size - 1)
    {
        std::cout << "Queue is Full!" << std::endl;
    }
    else
    {
        this->rear++; // rear holds just the index as the front
        this->Q[rear] = x;
    }
}

Node *Queue::dequeue()
{
    Node *temp = nullptr;

    if (this->front == this->rear)
    {
        std::cout << "Queue is empty!";
    }
    else
    {
        temp = this->Q[this->front + 1]; // since it's a queue the front element will be removed
        this->front++;
    }
    return temp; // return the dequeued element
}

void Queue::Display()
{
    for (int i = front + 1; i <= rear; i++)
    {
        std::cout << this->Q[i] << " ";
    }
    std::cout << std::endl;
}

bool Queue::isEmpty()
{
    return (this->rear == this->front);
}