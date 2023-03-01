#include <iostream>

using namespace std;

class box
{
private:
    int length;
    int *breadth;
    int height;

public:
    box()
    {
        breadth = new int;
    }

    void set_dimensions(int length, int br, int height)
    {
        this->length = length;
        *breadth = br;
        this->height = height;
    }

    void show_data()
    {
        cout << "Length: " << this->length << endl;
        cout << "Breadth: " << *breadth << endl;
        cout << "Height: " << this->height << endl;
    }

    // Deep Copy constructor

    box(box &source)
    {
        this->length = source.length;
        breadth = new int;            // allocating new space from the memory
        *breadth = *(source.breadth); // what's inside the source.breadth will be stored into variable breadth
        this->height = source.height;
    }

    ~box()
    {
        delete breadth;
    }
};

int main(void)
{

    box first;
    first.set_dimensions(12, 14, 16);
    cout << "Values of the first object" << endl;
    first.show_data();

    box second = first;
    cout << "Values of the second object" << endl;
    second.show_data();

    return 0;
}