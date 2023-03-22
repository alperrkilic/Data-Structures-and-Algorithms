#ifndef ARRAY
#define ARRAY
#include <vector>

class Array
{
private:
    int *A;
    int size;
    int length = 0;

public:
    Array(int size);
    ~Array();

    void generate_elements();
    void fillRandom();
    void fillCustom();
    void display_elements();
    void insertion_sort();
    void bubble_sort();
    void selection_sort();
    void delete_element(int index);
    std::vector<int> linear_search(int key);
    int binary_search(int key);
    int get_element(int index);
    void set_index(int index, int value);
    int get_max();
    int get_min();
    int get_sum();
    int get_avg();
    void reverse_array();
    bool isSorted();
};

#endif