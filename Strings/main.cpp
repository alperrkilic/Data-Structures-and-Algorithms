#include <iostream>
#include <string>
#include "String.h"

int main(void)
{
    int size;

    std::cout << "Please enter the size: ";
    std::cin >> size;

    String String(size);

    String.set_string();
    String.display_string();
    String.count_words();
    String.find_duplicates();

    return 0;
}