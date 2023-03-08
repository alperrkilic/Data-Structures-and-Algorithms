#include <iostream>
#include <chrono>
#include <vector>
#include <cstdlib>

using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::nanoseconds;
using namespace std;

void insertionSort(vector<int> &vector)
{
    int j;

    for (int i = 1; i < vector.size(); i++)
    {
        int element = vector[i];

        for (j = i; j > 0 && vector[j - 1] < element; j--)
        {
            vector[j] = vector[j - 1];
        }
        vector[j] = element;
    }
}

void printVector(vector<int> &vector)
{
    for (auto x : vector)
    {
        cout << x << " ";
    }
    cout << endl;
}

void generateVector(vector<int> &vector, int size)
{
    for (int i = 0; i < size; i++)
    {
        int random_number = 1 + (rand() % 1000); // generating and pushing random numbers into our vector between 1-1000
        vector.push_back(random_number);
    }
}

void calculateTime(vector<int> &vector, int index)
{
    auto t1 = high_resolution_clock::now();
    insertionSort(vector);
    auto t2 = high_resolution_clock::now();

    auto nanoint1 = duration_cast<nanoseconds>(t2 - t1);
    cout << "Sorting for vector " << index << " with " << vector.size() << " elements completed in " << nanoint1.count() << " ns" << endl;
}

int main(void)
{
    srand(time(NULL));

    vector<int> vector1;
    vector<int> vector2;
    vector<int> vector3;
    vector<int> vector4;
    vector<int> vector5;

    generateVector(vector1, 5); // sending the vector and its size
    generateVector(vector2, 10);
    generateVector(vector3, 15);
    generateVector(vector4, 20);
    generateVector(vector5, 25);

    calculateTime(vector1, 1); // calculating the time and sending the index to indicate the vector
    calculateTime(vector2, 2);
    calculateTime(vector3, 3);
    calculateTime(vector4, 4);
    calculateTime(vector5, 5);

    return 0;
}