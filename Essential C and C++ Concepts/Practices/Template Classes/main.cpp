#include <iostream>

using namespace std;

template <class T>
class Arithmetic
{

private:
    T a;
    T b;

public:
    Arithmetic(T a, T b);
    T add();
};

template <class T>
T Arithmetic<T>::add()
{
    T c;
    c = this->a + this->b;
    return c;
}

template <class T>
Arithmetic<T>::Arithmetic(T a, T b)
{
    this->a = a;
    this->b = b;
}

int main(void)
{
    cout << "Integer: ";
    Arithmetic<int> a(10, 5);
    cout << a.add() << endl;

    cout << "Float: ";
    Arithmetic<float> b(1.7, 2.5);
    cout << b.add() << endl;

    return 0;
}