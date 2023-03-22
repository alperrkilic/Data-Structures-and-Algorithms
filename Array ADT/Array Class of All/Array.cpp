#include "Array.h"

Array::Array(int size)
{
    this->size = size;
    A = new int[size];
}

Array::~Array()
{
    delete[] A;
}

void Array::insertion_sort()
{
}

void Array::bubble_sort()
{
}

void Array::selection_sort()
{
}

void Array::delete_element(int index)
{
}

void Array::linear_search(int key)
{
}

void Array::binary_search(int key)
{
}

int Array::get_element(int index)
{
    return 0;
}

void Array::set_index(int index, int value)
{
}

int Array::get_max()
{
    return 0;
}

int Array::get_min()
{
    return 0;
}

int Array::get_sum()
{
    return 0;
}

int Array::get_avg()
{
    return 0;
}

void Array::reverse_array()
{
}

bool Array::isSorted()
{
    return false;
}
