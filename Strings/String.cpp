#include "String.h"
#include <iostream>
#include <string>
#include <cctype>
#include <stdio.h>

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
    std::cin.ignore();

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

void String::count_words()
{
    int word_num{1};

    for (int i = 0; this->str[i] != '\0'; i++)
    {
        if (this->str[i] == ' ' && this->str[i - 1] != ' ')
        {
            word_num++;
        }
    }

    std::cout << "Number of words is: " << word_num << std::endl;
}

void String::find_duplicates()
{
    int H[26];
    char *temp_str = new char[this->size];

    for (int i = 0; this->str[i] != '\0'; i++)
    {
        temp_str[i] = this->str[i];
        tolower(temp_str[i]);
    }

    for (int i = 0; this->str[i] != '\0'; i++)
    {
        H[(temp_str[i] - 97)]++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (H[i] > 1)
        {
            printf("%c occurs %d times.\n", (i + 97), H[i]);
        }
    }
}