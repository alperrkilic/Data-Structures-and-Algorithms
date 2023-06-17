#include <iostream>

using namespace std;

template <typename T>
class Queue // circular queue code
{
private:
    T *data;
    int capacity; // holds the max capacity of the queues
    int size;     // holds the number of current elements in queue

    int rear;
    int front;

public:
    Queue(int capacity)
    {
        this->capacity = capacity;
        this->data = new T[this->capacity];
        this->size = 0;
        this->rear = this->front = 0;
    }
    ~Queue() { delete[] this->data; }
    void enqueue(T data)
    {
        if (this->is_full())
        {
            return
        }
        else
        {
            this->rear = (this->rear + 1) % this->capacity;
            this->data[this->rear] == data;
            this->size++;
        }
    }

    // template <class T>
    // T Queue<T>::dequeue()
    T dequeue()
    {
        if (this->is_empty())
        {
            return -1;
        }
        else
        {
            this->front = (this->front + 1) % this->capacity;
            T temp = this->data[this->front];
            this->size--;
            return temp;
        }
    }
    bool is_full()
    {
        if ((this->rear + 1) % this->capacity == this->front)
        {
            cout << "Queue is Full!" << endl;
            return true;
        }
        return false;
    }
    bool is_empty()
    {
        if (this->rear == this->front)
        {
            cout << "Queue is empty!" << endl;
            return true;
        }
        return false;
    }
};

int main(void)
{
    return 0;
}