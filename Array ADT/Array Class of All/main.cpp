#include <iostream>
#include "Array.h"

using namespace std;

int main(void)
{
    Array arr(5);

    arr.generate_elements();
    arr.display_elements();

    return 0;
}