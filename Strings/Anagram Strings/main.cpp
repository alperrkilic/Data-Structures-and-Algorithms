#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string A = "decimal";
    string B = "medical";

    int HashTable[26] = {0};

    for (int i = 0; i < A[i] != '\0'; i++)
    {
        HashTable[A[i] - 97] += 1;
    }

    int i;

    for (i = 0; i < B[i] != '\0'; i++)
    {
        HashTable[B[i] - 97] -= 1;

        if (HashTable[B[i] - 97] < 0)
        {
            cout << "Not Anagram" << endl;
            break;
        }
    }

    if (B[i] == '\0')
    {
        cout << "Strings Are Anagram of each other" << endl;
    }

    return 0;
}

/*
    LOGIC:
    ------

    d e c i m a l --> 100 101 99 105 109 97 108 (ASCII Values)

    in hashtable, go to 100-97 and increment by one, go to 101,97 and increment by one ... go to 108-97 and increment by one
    after that process now let's head to medical

    m e d i c a l--> 109 101 ... -> for the first one, go to 109-97 and decrement by one. Initially values were 0 after they were incremented
    we know that they became 1 and now we decrement them if they are 0, then strings are anagram else, strings are not anagram of each other

    Time Complexity : O(n)

*/