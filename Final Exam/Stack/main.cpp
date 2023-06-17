#include <iostream>

using namespace std;

template <typename T>
class Stack
{
private:
    int Top;
    int size;
    int *stack_arr;

public:
    Stack(int size)
    {
        this->Top = -1;
        this->size = size;
        this->stack_arr = new T[size];
    }

    void push_back(T data)
    {
        if (this->Top == this->size - 1)
        {
            cout << "Stack is Full!" << endl;
        }
        else
        {
            this->Top++;
            this->stack_arr[this->Top] = data;
        }
    }

    T pop()
    {
        T temp;

        if (this->Top == -1)
        {
            cout << "Stack is Empty!" << endl;
            return;
        }
        else
        {
            temp = this->stack_arr[this->Top];
            this->Top--;
            return temp;
        }
    }

    // template <class T>
    // T Stack<T>::Top()
    T Top()
    {
        return this->stack_arr[this->Top];
    }

    bool is_Full()
    {
        return this->Top == this->size - 1;
    }

    bool is_empty()
    {
        return this->Top == -1;
    }
};

int main(void)
{
    return 0;
}