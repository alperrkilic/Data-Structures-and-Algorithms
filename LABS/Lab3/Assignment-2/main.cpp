#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <chrono>

using namespace std;
using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::nanoseconds;

void swap(int &a, int &b);

class Matrix
{
private:
    int rows = 500;
    int cols = 500;
    vector<vector<int>> matrix;
    vector<vector<int>> sparse_matrix;

public:
    int nonzero = 0;
    Matrix();
    ~Matrix();

    void printMatrix();
    void printSparseMatrix();
    void make_transpose();        // matrix transpose
    void make_sparse_transpose(); // sparse_matrix_transpose
};

void Matrix::make_sparse_transpose()
{
    // Create a new empty sparse matrix to store the transpose
    std::vector<std::vector<int>> transpose_sparse_matrix_temp(3);
    transpose_sparse_matrix_temp[0].resize(nonzero);
    transpose_sparse_matrix_temp[1].resize(nonzero);
    transpose_sparse_matrix_temp[2].resize(nonzero);

    // Compute the number of non-zero elements in each column of the original matrix
    std::vector<int> col_non_zero(cols, 0);
    for (int i = 0; i < nonzero; i++)
    {
        col_non_zero[sparse_matrix[1][i] - 1]++;
    }

    // Compute the list heads for the transpose matrix
    std::vector<int> list_heads(cols + 1, 0);
    for (int j = 1; j <= cols; j++)
    {
        list_heads[j] = list_heads[j - 1] + col_non_zero[j - 1];
    }

    // Compute the transpose of the matrix
    for (int i = 0; i < nonzero; i++)
    {
        int j = sparse_matrix[1][i];
        int index = list_heads[j - 1];

        transpose_sparse_matrix_temp[0][index] = j;
        transpose_sparse_matrix_temp[1][index] = sparse_matrix[0][i];
        transpose_sparse_matrix_temp[2][index] = sparse_matrix[2][i];

        list_heads[j - 1]++;
    }

    this->sparse_matrix = transpose_sparse_matrix_temp;
}

void Matrix::make_transpose()
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = i + 1; j < matrix[i].size(); j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void Matrix::printMatrix()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void Matrix::printSparseMatrix()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < nonzero; j++)
        {
            cout << sparse_matrix[i][j] << " ";
        }
        cout << endl;
    }
}

Matrix::Matrix()
{
    matrix = vector<vector<int>>(rows, vector<int>(cols, 0)); // Initializing matrix with 0s

    vector<int> row_temp;
    vector<int> column_temp;
    vector<int> value_temp;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int random = (rand() % 125);
            if (random <= 123)
            {
                random = 0;
            }

            matrix[i][j] = random;
            if (matrix[i][j] != 0)
            {
                row_temp.push_back(i + 1);          // 1 1 2 2 4 4
                column_temp.push_back(j + 1);       // 3 5 3 4 2 3
                value_temp.push_back(matrix[i][j]); // 3 4 5 7 2 6
                nonzero++;
            }
        }
    }

    sparse_matrix.push_back(row_temp);
    sparse_matrix.push_back(column_temp);
    sparse_matrix.push_back(value_temp);
}

Matrix::~Matrix()
{
}

int main(void)
{
    srand(time(NULL));

    // Generating Original Matrix & Sparse Matrix. After that, displaying them

    Matrix m1;

    cout << "Original Matrix:" << endl;
    cout << "---------------------" << endl;
    // m1.printMatrix();
    cout << endl;

    // cout << m1.nonzero; // indicates how many columns will the sparse matrix have.

    cout << "Sparse Matrix:" << endl;
    cout << "----------------------" << endl;
    // m1.printSparseMatrix();
    cout << endl;

    // Now, we must have the transpose of the matrix

    cout << "Transpose of the Original Matrix: " << endl;
    cout << "----------------------" << endl;
    auto t1 = high_resolution_clock::now();
    m1.make_transpose();
    auto t2 = high_resolution_clock::now();
    // m1.printMatrix();
    cout << endl;

    cout << m1.nonzero << endl;

    cout << "Transpose of the Sparse Matrix: " << endl;
    cout << "----------------------" << endl;
    auto t3 = high_resolution_clock::now();
    m1.make_sparse_transpose();
    auto t4 = high_resolution_clock::now();
    // m1.printSparseMatrix();
    cout << endl;

    auto nanoint1 = duration_cast<nanoseconds>(t2 - t1);
    auto nanoint2 = duration_cast<nanoseconds>(t4 - t3);

    cout << "Time for Normal Matrix to transpose : " << nanoint1.count() << "ns" << endl;
    cout << "Time for Sparse Matrix to transpose : " << nanoint2.count() << "ns" << endl;

    cout << nanoint1.count() / nanoint2.count() << endl;

    /*
        Time for Normal Matrix to transpose : 2733549ns
        Time for Sparse Matrix to transpose : 148934ns
        18 times faster (from online compiler)
    */

    return 0;
}