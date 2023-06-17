#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &A, int x) // might be an exam question (x is the key)
{
    int first = 0, last = A.size() - 1;
    int mid;

    while (first <= last)
    {
        mid = (first + last) / 2;
        if (A[mid] == x)
        {
            return mid;
        }
        if (A[mid] > x)
        {
            last = mid - 1;
        }
        else
        {
            first = mid + 1;
        }
    }
    return -1;
}

int main(void)
{
    vector<int> A = {3, 4, 6, 8, 9};

    cout << "Searching 5: pos = " << binarySearch(A, 5) << endl;
    cout << "Searching 4: pos = " << binarySearch(A, 4) << endl;
    cout << "Searching 9: pos = " << binarySearch(A, 9) << endl;

    return 0;
}