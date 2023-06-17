#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <chrono>
#include <iomanip>

using namespace std;
using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::nanoseconds;

struct sparse
{
    int rows;
    int cols;
    int value;
};

class sparseMatrix
{
private:
    vector<sparse> sparse_vector;
    int nonzero = 0;

public:
    friend ostream &operator<<(ostream &os, const sparseMatrix &object);

    sparseMatrix(/* args */);
    ~sparseMatrix();

    void pushSparse(sparse &temp);
    void increaseNonzero();
    sparseMatrix make_transpose_sparse_matrix(int cols);
};

sparseMatrix sparseMatrix::make_transpose_sparse_matrix(int cols)
{
    // Create a new empty sparse matrix to store the transpose
    sparseMatrix transpose_matrix;
    transpose_matrix.nonzero = this->nonzero;

    transpose_matrix.sparse_vector = vector<sparse>(nonzero, sparse{0, 0, 0});

    // Compute the number of non-zero elements in each column of the original matrix
    std::vector<int>
        col_non_zero(cols, 0);
    for (int i = 0; i < this->nonzero; i++)
    {
        col_non_zero[this->sparse_vector[i].cols - 1]++;
    }

    // Compute the list heads for the transpose matrix
    std::vector<int> list_heads(cols + 1, 0);
    for (int j = 1; j <= cols; j++)
    {
        list_heads[j] = list_heads[j - 1] + col_non_zero[j - 1];
    }

    // Compute the transpose of the matrix
    for (int i = 0; i < this->nonzero; i++)
    {
        int j = this->sparse_vector[i].cols;
        int index = list_heads[j - 1];

        sparse temp = {.rows = this->sparse_vector[i].cols, .cols = this->sparse_vector[i].rows, .value = this->sparse_vector[i].value};
        transpose_matrix.sparse_vector[index] = temp;

        list_heads[j - 1]++;
    }

    return transpose_matrix;
}

void sparseMatrix::increaseNonzero()
{
    nonzero++;
}

sparseMatrix::sparseMatrix()
{
}

sparseMatrix::~sparseMatrix()
{
}

void sparseMatrix::pushSparse(sparse &temp)
{
    sparse_vector.push_back(temp);
}

void generateMatrix(sparseMatrix &object, vector<vector<int>> &normalMatrix, int &rows, int &cols)
{
    normalMatrix = vector<vector<int>>(rows, vector<int>(cols, 0)); // Initializing matrix with 0s

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int random = (rand() % 125);
            if (random <= 100)
            {
                random = 0;
            }

            normalMatrix[i][j] = random;
            if (normalMatrix[i][j] != 0)
            {
                sparse temp;
                temp.rows = i + 1;               // 1 1 2 2 4 4
                temp.cols = j + 1;               // 3 5 3 4 2 3
                temp.value = normalMatrix[i][j]; // 3 4 5 7 2 6
                object.pushSparse(temp);
                object.increaseNonzero();
            }
        }
    }
}
ostream &operator<<(ostream &os, const sparseMatrix &object)
{
    for (int i = 0; i < object.sparse_vector.size(); i++)
    {
        os << setw(4) << left << object.sparse_vector.at(i).rows;
    }

    os << endl;

    for (int i = 0; i < object.sparse_vector.size(); i++)
    {
        os << setw(4) << left << object.sparse_vector.at(i).cols;
    }

    os << endl;

    for (int i = 0; i < object.sparse_vector.size(); i++)
    {
        os << setw(4) << left << object.sparse_vector.at(i).value;
    }

    os << endl;

    return os;
}

void printOriginalMatrix(vector<vector<int>> &normalMatrix)
{
    for (size_t i = 0; i < normalMatrix.size(); i++)
    {
        for (int j = 0; j < normalMatrix[i].size(); j++)
        {
            cout << setw(6) << left << normalMatrix[i][j];
        }
        cout << endl;
    }
}

int main(void)
{
    srand(time(NULL));

    vector<vector<int>> normalMatrix;
    sparseMatrix object;

    int rows, cols;

    cout << "Please enter number of rows: ";
    cin >> rows;
    cout << "Please enter number of columns: ";
    cin >> cols;

    generateMatrix(object, normalMatrix, rows, cols);

    cout << "Normal Matrix: \n"
         << endl;

    printOriginalMatrix(normalMatrix);

    cout << "\nSparse Matrix" << endl;

    cout << object;

    // returning the new transposed matrix and storing it into transposed_sparse_matrix as it's asked in the question
    sparseMatrix transposed_sparse_matrix = object.make_transpose_sparse_matrix(cols);

    cout << endl
         << "Transposed Sparse Matrix" << endl;
    cout << transposed_sparse_matrix;
    cout << endl;

    return 0;
}