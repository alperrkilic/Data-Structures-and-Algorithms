#include <iostream>

using namespace std;

class Rectangle
{
private:
    int length;
    int breadth;

public:
    // Constructors
    Rectangle(int length, int breadth);

    // Methods

    void calculateArea();

    // setters
    void set_length(int length) { this->length = length; }
    void set_breadth(int breadth) { this->breadth = breadth; }
    // getters
    int get_length() { return this->length; }
    int get_breadth() { return this->breadth; }
};

Rectangle::Rectangle(int length, int breadth)
{
    this->length = length;
    this->breadth = breadth;
}

void Rectangle::calculateArea()
{
    cout << "Area is: " << this->length * this->breadth << endl;
}

int main(void)
{

    Rectangle r1(10, 5);

    r1.calculateArea();

    return 0;
}