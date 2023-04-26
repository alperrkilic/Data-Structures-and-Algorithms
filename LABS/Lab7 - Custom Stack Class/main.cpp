#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Stack
{
private:
    int Top = -1;
    vector<T> stackVector;

public:
    Stack() {}
    ~Stack() {}
    T get_top();
    int get_size();
    void pop();
    void append(T element);
    void swap();
};

template <class T>
T Stack<T>::get_top()
{
    if (this->Top != -1)
    {
        return this->stackVector.at(Top);
    }
    else
    {
        return -1;
    }
}

template <class T>
int Stack<T>::get_size()
{
    return this->stackVector.size();
}

template <class T>
void Stack<T>::pop()
{
    if (this->Top != -1)
    {
        this->stackVector.pop_back();
        this->Top--;
    }
}

template <class T>
void Stack<T>::append(T element)
{
    this->stackVector.push_back(element);
    this->Top++;
}

template <class T>
void Stack<T>::swap()
{
    if (this->Top >= 1) // meaning that we have at least 2 elements for the stackVector and we can swap them
    {
        T temp;
        temp = this->stackVector.at(Top);                          // temp has last element
        this->stackVector.at(Top) = this->stackVector.at(Top - 1); // Top = Top-1
        this->stackVector.at(Top - 1) = temp;                      // Top-1 = temp(Top)
    }
}

int main(void)
{

    // Test the Code:

    Stack<int> stack;

    stack.append(5);
    stack.append(10);
    stack.append(15);

    stack.pop();

    auto x = stack.get_top();
    cout << "Top Element is: " << x << endl;

    int s = stack.get_size();
    cout << "Size is: " << s << endl;

    stack.swap();
    x = stack.get_top();
    cout << "New Top after swap: " << x << endl;

    return 0;
}
