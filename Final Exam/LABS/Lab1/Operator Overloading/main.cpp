#include <iostream>

using namespace std;

class Complex
{
private:
    int real, imag;

public:
    Complex(int r = 0, int i = 0)
    {
        real = r;
        imag = i;
    }

    Complex operator+(Complex const &obj)
    {
        Complex res;
        res.real = this->real + obj.real;
        res.imag = this->imag + obj.imag;
        return res;
    }

    friend ostream &operator<<(ostream &os, const Complex &complex);
};

ostream &operator<<(ostream &os, const Complex &complex)
{
    os << complex.real << " + " << complex.imag << "i" << endl;
    return os;
}

int main(void)
{

    Complex num1(2, 3);
    Complex num2(3, 6);
    Complex num3 = num1 + num2;

    cout << num3 << endl; // 5 + 9i

    return 0;
}