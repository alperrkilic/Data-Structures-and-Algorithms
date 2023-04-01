#include <iostream>

using namespace std;

class Element
{
public:
    int i;
    int j;
    int x;
};

class Sparse
{
private:
    int m;
    int n;
    int num;
    Element *ele;

public:
    Sparse(int m, int n, int num);
    ~Sparse();

    Sparse operator+(Sparse &s);
    friend istream &operator>>(istream &is, Sparse &s);
    friend ostream &operator<<(ostream &os, Sparse &s);
};

Sparse Sparse::operator+(Sparse &s)
{
    int i, j, k;
    i = j = k = 0;

    if (m != s.m || n != s.n)
    {
        return Sparse(0, 0, 0);
    }

    Sparse *sum = new Sparse(m, n, num + s.num);

    while (i < this->num && j < s.num)
    {
        if (this->ele[i].i < s.ele[j].i) // compare rows
        {
            sum->ele[k++] = this->ele[i++];
        }
        else if (this->ele[i].i > s.ele[j].i)
        {
            sum->ele[k++] = s.ele[j++];
        }
        else // rows are equal
        {
            if (this->ele[i].j < s.ele[j].j)
            {
                sum->ele[k++] = this->ele[i++];
            }
            else if (this->ele[i].j > s.ele[j].j)
            {
                sum->ele[k++] = s.ele[j++];
            }
            else
            {
                sum->ele[k] = this->ele[i];
                sum->ele[k++].x = this->ele[i++].x + s.ele[j++].x;
            }
        }
    }

    for (; i < this->num; i++)
    {
        sum->ele[k++] = this->ele[i];
    }

    for (; j < s.num; j++)
    {
        sum->ele[k++] = s.ele[j];
    }

    sum->num = k;

    return *sum;
}

ostream &
operator<<(ostream &os, Sparse &s)
{
    int k = 0;

    for (int i = 0; i < s.m; i++)
    {
        for (int j = 0; j < s.n; j++)
        {
            if (s.ele[k].i == i && s.ele[k].j == j)
            {
                os << s.ele[k++].x << " ";
            }
            else
            {
                os << "0 ";
            }
        }
        os << endl;
    }

    return os;
}

istream &operator>>(istream &is, Sparse &s)
{
    cout << "Enter non-zero elements" << endl;

    for (int i = 0; i < s.num; i++)
    {
        is >> s.ele[i].i >> s.ele[i].j >> s.ele[i].x;
    }

    return is;
}

Sparse::Sparse(int m, int n, int num)
{
    this->m = m;
    this->n = n;
    this->num = num;
    this->ele = new Element[this->num];
}

Sparse::~Sparse()
{
    delete[] this->ele;
}

int main(void)
{
    Sparse s1(5, 5, 5);
    Sparse s2(5, 5, 5);
    cin >> s1;
    cin >> s2;

    Sparse sum = s1 + s2;

    cout << "First Matrix" << endl
         << s1 << endl;

    cout << "Second Matrix" << endl
         << s2 << endl;

    cout << "Sum Matrix" << endl
         << sum << endl;

    return 0;
}