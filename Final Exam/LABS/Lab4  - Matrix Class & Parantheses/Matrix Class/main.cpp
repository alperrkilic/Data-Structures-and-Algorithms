#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Matrix
{
private:
    int row_num;
    int col_num;
    vector<vector<int>> matrix_vector;

public:
    // Constructor & Destructor
    Matrix(int row_num, int col_num);
    ~Matrix();

    // Methods
    int get_row_num() const;
    int get_col_num() const;
    void set_matrix_element(int i, int j, int x);
    int get_matrix_element(int i, int j) const;

    // Friend Functions:
    // Addition operator overloads
    friend Matrix operator+(const Matrix &m1, int num_to_add);
    friend Matrix operator+(const Matrix &m1, const Matrix m2);
    // Subtraction operator overloads
    friend Matrix operator-(const Matrix &m1, int num_to_sub);
    friend Matrix operator-(const Matrix &m1, const Matrix &m2);
    // Multiplication and division operator overloads
    friend Matrix operator/(const Matrix &m, int div);
    friend Matrix operator*(const Matrix &m, int mul);
    // istream & ostream operator overloads
    friend istream &operator>>(istream &is, Matrix &m);
    friend ostream &operator<<(ostream &os, Matrix &m);
};

Matrix operator-(const Matrix &m1, int num_to_sub)
{
    Matrix result(m1.get_row_num(), m1.get_col_num());
    int temp;

    for (int i = 0; i < result.get_row_num(); i++)
    {
        for (int j = 0; j < result.get_col_num(); j++)
        {
            temp = m1.get_matrix_element(i, j) - num_to_sub;
            result.set_matrix_element(i, j, temp);
        }
    }

    return result;
}

Matrix operator-(const Matrix &m1, const Matrix &m2)
{
    if (m1.get_row_num() != m2.get_row_num() || m1.get_col_num() != m2.get_col_num()) // in order to subtract matrix dimensions must be equal.
    {
        throw std::runtime_error("Matrix dimensions does not match !");
    }

    Matrix result(m1.get_row_num(), m1.get_col_num()); // it could be m2 as well since we're checked that their dimensions are equal
    int temp;

    for (int i = 0; i < result.get_row_num(); i++)
    {
        for (int j = 0; j < result.get_col_num(); j++)
        {
            temp = m1.get_matrix_element(i, j) - m2.get_matrix_element(i, j);
            result.set_matrix_element(i, j, temp);
        }
    }

    return result;
}

Matrix operator+(const Matrix &m1, int num_to_add)
{
    Matrix result(m1.get_row_num(), m1.get_col_num());
    int temp;

    for (int i = 0; i < result.get_row_num(); i++)
    {
        for (int j = 0; j < result.get_col_num(); j++)
        {
            temp = m1.get_matrix_element(i, j) + num_to_add;
            result.set_matrix_element(i, j, temp);
        }
    }

    return result;
}

Matrix operator+(const Matrix &m1, const Matrix m2)
{
    if (m1.get_row_num() != m2.get_row_num() || m1.get_col_num() != m2.get_col_num()) // checking that dimensions must be equal to perform addition
    {
        throw std::runtime_error("Matrix dimensions does not match !");
    }

    Matrix result(m1.get_row_num(), m1.get_col_num()); // since dimensions are equal we could also say m2.get_row_num() nothing would change
    int temp;

    for (int i = 0; i < result.get_row_num(); i++)
    {
        for (int j = 0; j < result.get_col_num(); j++)
        {
            temp = m1.get_matrix_element(i, j) + m2.get_matrix_element(i, j);
            result.set_matrix_element(i, j, temp);
        }
    }

    return result;
}

Matrix operator/(const Matrix &m, int div)
{
    Matrix result(m.get_row_num(), m.get_col_num());
    int temp;

    for (int i = 0; i < result.get_row_num(); i++)
    {
        for (int j = 0; j < result.get_col_num(); j++)
        {
            temp = m.get_matrix_element(i, j) / div;
            result.set_matrix_element(i, j, temp);
        }
    }

    return result;
}

Matrix operator*(const Matrix &m, int mul)
{
    Matrix result(m.get_row_num(), m.get_col_num());
    int temp;

    for (int i = 0; i < result.get_row_num(); i++)
    {
        for (int j = 0; j < result.get_col_num(); j++)
        {
            temp = m.get_matrix_element(i, j) * mul;
            result.set_matrix_element(i, j, temp);
        }
    }

    return result;
}

int Matrix::get_matrix_element(int i, int j) const
{
    return this->matrix_vector[i][j];
}

void Matrix::set_matrix_element(int i, int j, int x)
{
    this->matrix_vector[i][j] = x;
}

int Matrix::get_row_num() const
{
    return this->row_num;
}

int Matrix::get_col_num() const
{
    return this->col_num;
}

Matrix::Matrix(int row_num, int col_num)
{
    this->col_num = col_num;
    this->row_num = row_num;
    this->matrix_vector = vector<vector<int>>(row_num, vector<int>(col_num, 0)); // initializing all elements of the vector to 0
}

istream &operator>>(istream &is, Matrix &m)
{
    cout << "\nPlease enter elements: " << endl;

    int temp;

    for (int i = 0; i < m.get_row_num(); i++)
    {
        cout << "Row-" << i + 1 << ": ";
        for (int j = 0; j < m.get_col_num(); j++)
        {
            is >> temp;
            m.set_matrix_element(i, j, temp);
        }
    }

    return is;
}

ostream &operator<<(ostream &os, Matrix &m)
{

    os << "\nMatrix (" << m.get_row_num() << " x " << m.get_col_num() << ")" << endl;
    os << setw(3) << left;

    for (int i = 0; i < m.get_row_num(); i++)
    {
        for (int j = 0; j < m.get_col_num(); j++)
        {
            os << setw(3) << m.get_matrix_element(i, j) << " ";
        }
        os << endl;
    }

    return os;
}

Matrix::~Matrix()
{
}

int main(void)
{
    Matrix m1(3, 3); // initially all elements are 0
    Matrix m2(3, 3);

    // cout << "istream & ostream operator overloads" << endl;
    cin >> m1;
    cin >> m2;
    // cout << m1;

    // cout << "Multiplication" << endl;
    // m1 = m1 * 6;
    // cout << m1;

    // cout << "Division" << endl;
    // m1 = m1 / 2;
    // cout << m1;

    try
    {
        cout << "\nAddition - m3" << endl;
        Matrix m3 = m1 + m2; // two matrix addition
        cout << m3;
        cout << "\nSubtraction - m4" << endl;
        Matrix m4 = m1 - m2;
        cout << m4;
        cout << "\nm1 = m1 + 3" << endl;
        m1 = m1 + 3; // adding a specific number to the all elements of the matrix
        cout << m1;
        cout << "\nm4 = m4 -2" << endl;
        m4 = m4 - 2; // subtracting a specific number from all elements of a matrix
        cout << m4;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught Exception: " << e.what() << '\n';
    }

    return 0;
}