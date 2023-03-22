#include "Array.h"
#include <math.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

void swap_elements(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

Array::Array(int size)
{
    this->size = size;
    A = new int[size];
}

Array::~Array()
{
    delete[] A;
}

void Array::generate_elements()
{
    int choice;
    std::cout << "1 - Fill array with random elements" << std::endl;
    std::cout << "2 - Fill array with custom elements" << std::endl;
    std::cout << "Please Enter your choice: ";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        fillRandom();
        break;
    case 2:
        fillCustom();
        break;
    default:
        break;
    }
}

void Array::fillRandom()
{
    srand(time(NULL));

    for (int i = 0; i < this->size; i++)
    {
        this->A[i] = 1 + (rand() % 25);
    }
    this->length = this->size;
}

void Array::fillCustom()
{
    int number_of_elements;
    std::cout << "Please enter number of elements to enter: ";
    std::cin >> number_of_elements;

    if (number_of_elements < 0)
    {
        throw "Number of elements cannot be smaller than 0.";
    }

    if (number_of_elements > this->size)
    {
        throw "Number of elements cannot be bigger than size.";
    }

    this->length = number_of_elements;

    for (int i = 0; i < number_of_elements; i++)
    {
        std::cout << "Element - " << i + 1 << ": ";
        std::cin >> this->A[i];
    }
}

void Array::display_elements()
{
    for (int i = 0; i < this->length; i++)
    {
        std::cout << this->A[i] << " ";
    }
    std::cout << std::endl;
}

void Array::bubble_sort()
{
    bool condition = isSorted();

    if (condition)
    {
        int flag;

        for (int i = 0; i < this->length; i++)
        {
            flag = 0;
            for (int j = 0; j < this->length - i; j++) // minus i because on every pass one comparison will be reduced since one of the elements will be sorted
            {
                if (this->A[j] > this->A[j + 1])
                {
                    swap_elements(this->A[j], this->A[j + 1]);
                    flag = 1;
                }
            }
            if (flag == 0)
            {
                break;
            }
        }
    }
    else
    {
        std::cout << "This array is already sorted." << std::endl;
    }
}

void Array::insertion_sort()
{

    bool condition = isSorted();

    if (condition)
    {
        int j, x;
        for (int i = 1; i < this->length; i++)
        {
            j = i - 1;
            x = this->A[i];
            while (j > -1 && this->A[j] > x)
            {
                this->A[j + 1] = this->A[j];
                j--;
            }
            this->A[j + 1] = x;
        }
    }
    else
    {
        std::cout << "This array is already sorted." << std::endl;
    }
}

void Array::selection_sort()
{
    bool condition = isSorted();

    if (condition)
    {
        for (int i = 0; i < this->length; i++)
        {
            int k = i;
            for (int j = i; j < this->length; j++)
            {
                if (this->A[j] < this->A[k])
                {
                    k = j;
                }
            }
            swap_elements(this->A[i], this->A[k]);
        }
    }
    else
    {
        std::cout << "This array is already sorted." << std::endl;
    }
}

void Array::delete_element(int index)
{
    for (int i = index; i < this->length; i++)
    {
        this->A[i] = this->A[i + 1];
    }
    this->length--;
}

std::vector<int> Array::linear_search(int key)
{
    if (this->length != 0)
    {
        std::vector<int> FoundElementIndex;

        for (int i = 0; i < this->length; i++)
        {
            if (key == this->A[i])
            {
                FoundElementIndex.push_back(i);
            }
        }
        return FoundElementIndex;
    }
    else
    {
        throw "Array is empty";
    }
}

int Array::binary_search(int key)
{
    bool condition;
    condition = isSorted();

    if (condition)
    {
        int low = 0;
        int high = this->length;
        int mid;

        while (low <= high)
        {
            mid = floor((low + high) / 2);

            if (key == this->A[mid])
            {
                return mid;
            }
            else if (key < A[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return -1;
    }
    else
    {
        throw "Array is not sorted. Please sort the array first.";
    }
}

int Array::get_element(int index)
{
    if (index >= 0 && index < this->length)
    {
        return this->A[index];
    }
    else
    {
        throw "Invalid index. There was an error with getting the element.";
    }

    return 0;
}

void Array::set_index(int index, int value)
{
    if (index >= 0 && index < this->length)
    {
        this->A[index] = value;
    }
    else
    {
        throw "Invalid Index. There was an error with setting to the index.";
    }
}

int Array::get_max()
{

    if (this->length == 0)
    {
        throw "Array is empty";
    }

    int max = this->A[0];

    for (int i = 0; i < this->length; i++)
    {
        if (this->A[i] > max)
        {
            max = this->A[i];
        }
    }

    return max;
}

int Array::get_min()
{
    if (this->length == 0)
    {
        throw "Array is empty.";
    }

    int min = this->A[0];

    for (int i = 0; i < this->length; i++)
    {
        if (this->A[i] < min)
        {
            min = this->A[i];
        }
    }

    return min;
}

int Array::get_sum()
{
    if (this->length == 0)
    {
        throw "Array is empty.";
    }

    int sum{0};

    for (int i = 0; i < this->length; i++)
    {
        sum = sum + this->A[i];
    }

    return sum;
}

int Array::get_avg()
{
    if (this->length == 0)
    {
        throw "Array is empty.";
    }

    int sum{0};

    for (int i = 0; i < this->length; i++)
    {
        sum = sum + this->A[i];
    }

    return (sum / this->length);
}

void Array::reverse_array()
{
    if (this->length == 0)
    {
        throw "Array is empty.";
    }

    int k = this->length - 1;
    for (int i = 0; i < k; i++)
    {
        swap_elements(this->A[i], this->A[k]);
        k -= i;
    }
}

bool Array::isSorted()
{
    if (this->length == 0)
    {
        throw "Array is empty.";
    }

    for (int i = 0; i < this->length; i++)
    {
        if (this->A[i] > this->A[i + 1])
        {
            return false;
        }
    }

    return true;
}