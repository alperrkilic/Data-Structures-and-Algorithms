#include <iostream>

using namespace std;

template <typename T>
class Stack
{
private:
    T *Data;
    int Top;
    int Size;

public:
    Stack(int sz = 10)
    {
        Data = new T[Size = sz];
        Top = -1;
    }
    ~Stack() { delete[] Data; }
    bool isEmpty() { return Top == -1; }
    bool isFull() { return Top == Size - 1; }
    T &top() { return Data[Top]; }
    void push(T val)
    {
        Top = Top + 1;
        Data[Top] = val;
    }
    void pop() { Top = Top - 1; }
    int getElementCount() { return Top + 1; }
};

int main(int argc, char *argv[])
{
    Stack<char> S1(5);
    for (char *t = argv[1]; *t != 0; t = t + 1)
    {
        if (*t == '(')
            S1.push('(');
        if (*t == ')')
        {
            if (S1.isEmpty())
            {
                cout << "mismatched right paranthesis" << endl;
                return (-1);
            }
            S1.pop();
        }
    }
    if (S1.isEmpty())
    {
        cout << "SUCCESS: all left parantheses are matched" << endl;
        return 0;
    }
    cout << "FAIL: Stack has " << S1.getElementCount() << " left parantheses unmatched" << endl;

    return -1;
}
