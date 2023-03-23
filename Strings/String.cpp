#include "String.h"
#include <iostream>
#include <string>

String::String(int size)
{
    this->str = new char[size];
    this->size = size;
}

String::~String()
{
    delete[] str;
}

int String::find_strlen()
{
    int length = 0;

    for (int i = 0; this->str[i] != '\0'; i++)
    {
        length++;
    }

    return length;
}

void String::set_string()
{
    std::string temp_str;
    std::cout << "Please enter your string with max size " << this->size << ": ";
    std::getline(std::cin, temp_str);

    for (int i = 0; i < this->size; i++)
    {
        this->str[i] = temp_str[i];
    }
}

void String::display_string()
{
    int length = find_strlen();

    for (int i = 0; i < length; i++)
    {
        std::cout << this->str[i];
    }
    std::cout << std::endl;
}
