#include <iostream>
#include <vector>

using namespace std;

void insSort(vector<int> &A) // insertion sort, very important to know
{
    for (int i = 1; i < A.size(); i++)
    {
        int temp = A[i]; // item to be inserted
        int j = i - 1;   // compare with the last element

        while (j >= 0 && temp < A[j])
        {
            A[j + 1] = A[j];
            j--;
        }
    }
}

bool isSorted(vector<int> &A)
{
    for (int i = 0; i < A.size() - 1; i++)
    {
        if (A[i] > A[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main(void)
{
    vector<int> A = {3, 4, 6, 8, 9};
    vector<int> B = {9, 8, 6, 4, 3};

    cout << boolalpha;
    cout << "A is sorted: " << isSorted(A) << endl;
    cout << "B is sorted: " << isSorted(B) << endl;

    return 0;
}