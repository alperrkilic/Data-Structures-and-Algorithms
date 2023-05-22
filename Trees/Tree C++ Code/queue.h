#ifndef QUEUE
#define QUEUE
#include <stdio.h>
#include <iostream>
#include "node.h"

class Queue
{
private:
    int front;
    int rear;
    int size;
    Node **Q;

public:
    Queue();
    Queue(int size);
    void enqueue(Node *x);
    Node *dequeue();
    void Display();
    bool isEmpty();
};

#endif