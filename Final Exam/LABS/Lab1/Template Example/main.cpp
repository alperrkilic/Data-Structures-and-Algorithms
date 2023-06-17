#include <iostream>
#include <stdio.h>

using namespace std;

// Template class
template <typename T>
class Array
{
private:
    T *ptr; // template pointer, which will be the array
    int size;

public:
    Array(T arr[], int s); // takes a template array and size
    void print();
};

template <typename T>
Array<T>::Array(T arr[], int s)
{
    ptr = new T[s]; // pointer points a place on the heap that is determined according to the template variables' type
    size = s;
    for (int i = 0; i < size; i++)
        ptr[i] = arr[i];
}

template <typename T>
void Array<T>::print()
{
    for (int i = 0; i < size; i++)
        cout << " " << *(ptr + i);
    cout << endl;
}

// Template function
template <typename T>
T findMax(T x, T y)
{
    if (x > y)
    {
        return x;
    }
    return y;
}

int main(void)
{

    cout << "Template function examples" << endl;
    // Template for float variable
    float x = 3.5;
    float y = 4.6;
    float z;
    z = findMax(x, y);
    cout << "1: " << z << endl;

    // Template for integer variable
    int a = 8;
    int b = 5;
    int c;
    c = findMax(a, b);
    cout << "2: " << c << endl;

    // Template for char variable
    char k = 'k';
    char p = 'p';
    char result;
    result = findMax(k, p);
    cout << "3: " << result << endl;

    // Template Array class
    cout << "Template Class Examples:" << endl;

    // printing the float array:
    float arr[5] = {2.3, 1.5, 3.6, 2.8, 9.4};
    Array<float> array(arr, 5);
    array.print();

    // printing the integer array:
    int Arr[5] = {1, 2, 3, 4, 5};
    Array<int> intArr(Arr, 5);
    intArr.print();

    return 0;
}