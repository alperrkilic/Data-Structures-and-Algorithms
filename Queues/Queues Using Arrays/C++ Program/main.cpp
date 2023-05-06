#include <iostream>

using namespace std;

class Queue
{
private:
    int size;
    int rear;
    int front;
    int *Q;

public:
    Queue(int size);
    ~Queue();

    void enqueue(int x);
    int dequeue();
    void display();
};

void Queue::enqueue(int x)
{
    if (this->rear == this->size - 1)
    {
        cout << "Queue is Full!" << endl;
    }
    else
    {
        this->rear++;
        this->Q[this->rear] = x;
    }
}

int Queue::dequeue()
{
    int x = -1;
    if (this->rear == this->front)
    {
        cout << "Queue is Empty!" << endl;
        this->rear = -1; // reinitialize the indexes so that we can use the free spaces
        this->front = -1;
    }
    else
    {
        x = this->Q[this->front + 1];
        this->front++;
    }
    return x;
}

void Queue::display()
{
    for (size_t i = this->front + 1; i <= this->rear; i++)
    {
        cout << this->Q[i] << " ";
    }
    cout << endl;
}

Queue::Queue(int size)
{
    this->size = size;
    this->rear = this->front = -1;
    this->Q = new int[this->size];
}

Queue::~Queue()
{
    delete this->Q;
}

int main(void)
{
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.dequeue();
    q.display();

    return 0;
}