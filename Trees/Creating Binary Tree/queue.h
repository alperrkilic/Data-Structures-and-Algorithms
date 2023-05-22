#ifndef QUEUE
#define QUEUE
#include <iostream>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue
{
    int size;
    int front;
    int rear;
    Node **Q;
};

void create(struct Queue *q, int size);
void enqueue(struct Queue *q, struct Node *x);
Node *dequeue(struct Queue *q);
int isEmpty(struct Queue q);

#endif